// created by Camilo <3CamiloSasukeThomasBorregaardSoerensen
// recreated by Camilo 2021-01-28 22:20 <3TBS, Mummi and bilbo!!
// hi5 contribution...
#include "framework.h"
#include "display.h"
#include "window.h"
#include "windowing.h"
#include "windowing_wayland.h"
#include "acme/constant/message.h"
#include "acme/parallelization/synchronous_lock.h"
#include "apex/platform/node.h"
#include "apex/platform/system.h"
#include "aura/platform/session.h"
#include "aura/user/user/user.h"
#include "aura/graphics/image/image.h"
#include "aura/windowing/desktop_environment.h"
#include "aura/windowing/monitor.h"
#include "aura_posix/node.h"
#include "aura_posix/x11/display_lock.h"
#include <X11/extensions/Xrender.h>
#include <wayland-client-protocol.h>

extern ::app_core * g_pappcore;

Display * x11_get_display();

::particle * user_synchronization();


void windowing_output_debug_string(const ::scoped_string & scopedstrDebugString);


namespace windowing_wayland
{

   void shm_format(void *data, struct wl_shm *wl_shm, uint32_t format)
   {
      const char *s;
      switch (format) {
         case WL_SHM_FORMAT_ARGB8888: s = "ARGB8888"; break;
         case WL_SHM_FORMAT_XRGB8888: s = "XRGB8888"; break;
         case WL_SHM_FORMAT_RGB565: s = "RGB565"; break;
         default: s = "other format"; break;
      }
      fprintf(stderr, "Possible shmem format %s\n", s);
   }

   struct wl_shm_listener shm_listener = {
      shm_format
   };


   void global_registry_handler(void *data, struct wl_registry *pwlregistry, uint32_t id,
                           const char *interface, uint32_t version)
   {

      auto pdisplay = (display*)data;

      if (strcmp(interface, "wl_compositor") == 0)
      {

         pdisplay->m_pwlcompositor = (::wl_compositor*)wl_registry_bind(pwlregistry, id, &wl_compositor_interface, 1);

      }
      else if (strcmp(interface, "wl_shell") == 0)
      {

         pdisplay->m_pwlshell = (::wl_shell*)wl_registry_bind(pwlregistry, id, &wl_shell_interface, 1);

      }
      else if (strcmp(interface, "wl_shm") == 0)
      {

         pdisplay->m_pwlshm = (::wl_shm*)wl_registry_bind(pwlregistry, id, &wl_shm_interface, 1);

         wl_shm_add_listener(pdisplay->m_pwlshm, &shm_listener, NULL);

      }

   }

   void global_registry_remover(void *data, struct wl_registry *registry, uint32_t id)
   {

      printf("Got a registry losing event for %d\n", id);

   }

   const struct wl_registry_listener registry_listener =
      {
      global_registry_handler,
      global_registry_remover
   };

   display::display()
   {

      zero(m_atoma);

      m_pDisplay = this;
      //m_colormap = None;
      //m_windowRoot = None;
      //m_px11display = nullptr;
      m_pwldisplay = nullptr;
      m_pwlshm = nullptr;
      m_pwlcompositor = nullptr;
      m_pwlshell = nullptr;
      m_pwlcursorSurface = nullptr;
//      m_atomLongType = None;
//      m_atomLongStyle = None;
//      m_atomNetWmState = None;
//      m_atomWmProtocols = None;
//      m_atomNetWmStateFocused = None;
//      m_atomNetWmStateHidden = None;
//      m_atomNetWmStateMaximizedHorz = None;
//      m_atomNetWmStateMaximizedVert = None;
//      m_atomNetWmSyncRequest = None;
//      m_atomNetWmSyncRequestCounter = None;
//      m_atomLongStyleEx = 0;
      m_countReference = 1;
      //m_bHasXSync = true;

   }


   display::~display()
   {

   }


#ifdef _DEBUG


   i64 display::get_ref_count()
   {

      return m_countReference;

   }


   i64 display::increment_reference_count(OBJECT_REFERENCE_COUNT_DEBUG_PARAMETERS)
   {

#ifdef WINDOWS

      return InterlockedIncrement64(&m_countReference);

#elif defined(RASPBERRYPIOS) && defined(OS32BIT)

      return __sync_add_and_fetch_4(&m_countReference,1);

#else

      return __sync_add_and_fetch(&m_countReference, 1);

#endif

   }


   i64 display::decrement_reference_count(OBJECT_REFERENCE_COUNT_DEBUG_PARAMETERS)
   {

#ifdef WINDOWS

      return InterlockedDecrement64(&m_countReference);

#elif defined(RASPBERRYPIOS) && defined(OS32BIT)

      return __sync_sub_and_fetch_4(&m_countReference,1);

#else

      return __sync_sub_and_fetch(&m_countReference, 1);

#endif

   }


   i64 display::release(OBJECT_REFERENCE_COUNT_DEBUG_PARAMETERS)
   {

      i64 i = decrement_reference_count(OBJECT_REFERENCE_COUNT_DEBUG_ARGS);

      return i;

   }


#endif // DEBUG


   Display * display::_get_system_default_display()
   {

      return nullptr;

   }


   void display::open()
   {

      if (::is_set(m_pwldisplay))
      {

         return;

      }

      ::pointer < ::aura_posix::node > pauraposixnode = acmenode();

      auto pwldisplay = pauraposixnode->get_wayland_display();

      m_pwldisplay = pwldisplay;

      auto pwlregistry = wl_display_get_registry(m_pwldisplay);

      wl_registry_add_listener(pwlregistry, &registry_listener, this);

      wl_display_dispatch(m_pwldisplay);

      wl_display_roundtrip(m_pwldisplay);


      m_pwlcursorSurface = wl_compositor_create_surface(m_pwlcompositor);

      bool bBranch = !acmesession()->m_paurasession->user()->m_pdesktopenvironment->m_bUnhook;

//      m_px11display->m_bUnhook = bUnhook;

      //auto px11displayGdk = _get_system_default_display();

      //m_px11display = ::x11::display::get(this, false, px11displayGdk);

      // Using another memory_new and different X11 Display connection apart from Gtk.
      //m_px11display = ::x11::display::get(this, false);

      //if (::is_null(m_px11display))
      //{

        // throw ::exception(error_failed);

      //}

      //_m_pX11Display = m_px11display->m_pdisplay;

      //m_px11display->m_bUnhook = true;

//      if (XMatchVisualInfo(m_px11display->m_pdisplay, DefaultScreen(m_px11display->m_pdisplay), 32, TrueColor,
//                           &m_visualinfo))
//      {
//
//         m_pvisual = m_visualinfo.visual;
//
//      }
//      else
//      {
//
//         zero(m_visualinfo);
//
//      }

//      ::Display * pdisplay = m_px11display->m_pdisplay;
//
//      m_iScreen = XDefaultScreen(pdisplay);
//
//      m_windowRoot = XRootWindow(pdisplay, m_iScreen);
//
//      m_iDepth = m_visualinfo.depth;
//
//      XSetWindowAttributes attr;
//
//      zero(attr);
//
//      m_colormap = XCreateColormap(m_px11display->m_pdisplay, m_windowRoot, m_pvisual, AllocNone);
//
//      m_bHasXSync = false;
//
//#ifdef HAVE_XSYNC
//
//      {
//
//         int error_base, event_base;
//
//         if (XSyncQueryExtension(m_px11display->m_pdisplay, &event_base, &error_base) &&
//             XSyncInitialize(m_px11display->m_pdisplay, &m_iXSyncMajor, &m_iXSyncMinor))
//         {
//
//            m_bHasXSync = true;
//
//         }
//
//      }
//
//#endif
//
//      if (m_bHasXSync)
//      {
//
//         information() << "Display supports XSync";
//
//      }
//      else
//      {
//
//         information() << "Display doesn't support XSync";
//
//      }

//      //m_atomCardinal = intern_atom("CARDINAL", True);
//      m_atomWmProtocols = intern_atom("WM_PROTOCOLS", True);
//      m_atomWmState = intern_atom("WM_STATE", false);
//      m_atomNetWmState = intern_atom("_NET_WM_STATE", false);
//      m_atomNetWmSyncRequest = intern_atom("_NET_WM_SYNC_REQUEST", True);
//      m_atomNetWmSyncRequestCounter = intern_atom("_NET_WM_SYNC_REQUEST_COUNTER", True);
//      m_atomNetWmStateFocused = intern_atom("_NET_WM_STATE_FOCUSED", True);
//      m_atomNetWmStateHidden = intern_atom("_NET_WM_STATE_HIDDEN", True);
//      m_atomNetWmStateMaximizedHorz = intern_atom("_NET_WM_STATE_MAXIMIZED_HORZ", True);
//      m_atomNetWmStateMaximizedVert = intern_atom("_NET_WM_STATE_MAXIMIZED_VERT", True);
//
//
//      long *workArea;
//      int format;
//      unsigned long items, bytesAfter;
//      uint8_t *prop;
//      Atom type;
//      Atom _NET_WORKAREA = XInternAtom(pdisplay, "_NET_WORKAREA", 0);
//      m_rectangleaWorkAreas.clear();
//      if(XGetWindowProperty(pdisplay, m_windowRoot,
//                            _NET_WORKAREA, 0, ~0, False,
//                            XA_CARDINAL, &type, &format, &items, &bytesAfter, (uint8_t **)&workArea) || !workArea)
//      {
//         warning("error getting desktop work area, using root window size");
//      }
//      else
//      {
//         //logMsg("work area: %ld:%ld:%ld:%ld", workArea[0], workArea[1], workArea[2], workArea[3]);
//         for(int iPos = 0; iPos + 3 < items; iPos+=4)
//         {
//            m_rectangleaWorkAreas.add(::rectangle_i32_dimension(
//               workArea[iPos], workArea[iPos+1],
//               workArea[iPos+2], workArea[iPos+3]));
//         }
//         XFree(workArea);
//      }
//
////      for(auto & r : rectanglea)
////      {
////         auto pmonitor = get_best_monitor(r);
////
////         if(::is_set(pmonitor))
////         {
////
////            pmonitor->set_workspace_rectangle(r);
////
////         }
////
////      }

   }


   ::windowing_wayland::window * display::_window(Window window)
   {

      if (!window)
      {

         return nullptr;

      }

      critical_section_lock synchronouslock(&m_criticalsectionWindowMap);

      auto passociation = m_windowmap.plookup(window);

      if (passociation.is_null())
      {

         return nullptr;

      }

      return passociation->m_element2;

   }


   void display::lock_display()
   {

      if (!is_main_thread())
      {

         information("not main thread");

      }

      //XLockDisplay(m_px11display->m_pdisplay);

   }


   void display::unlock_display()
   {

      //XUnlockDisplay(m_px11display->m_pdisplay);

   }


   ::Display * display::Display()
   {

      return ::is_null(this) ? nullptr : m_px11display->m_pdisplay;

   }


   ::Display * display::Display() const
   {

      return ::is_null(this) ? nullptr : m_px11display->m_pdisplay;

   }


   int display::Screen()
   {

      return ::is_null(this) ? 0 : m_iScreen;

   }


   int display::Screen() const
   {

      return ::is_null(this) ? 0 : m_iScreen;

   }


   Atom display::atom_long_type()
   {

      return ::is_null(this) ? 0 : m_atomLongType;

   }


   Atom display::atom_long_style()
   {

      return ::is_null(this) ? 0 : m_atomLongStyle;

   }


   Atom display::atom_long_style_ex()
   {

      return ::is_null(this) ? 0 : m_atomLongStyleEx;

   }


   bool display::is_null() const
   {

      return ::is_null(this);

   }


   bool display::get_monitor_rectangle(index iMonitor, ::rectangle_i32 & rectangle)
   {

      return ::windowing::display::get_monitor_rectangle(iMonitor, rectangle);

   }


   bool display::get_workspace_rectangle(index iMonitor, ::rectangle_i32 & rectangle)
   {

      return ::windowing::display::get_workspace_rectangle(iMonitor, rectangle);

   }


   ::windowing::window * display::get_mouse_capture()
   {

      return m_pwindowMouseCapture;

   }


   ::e_status display::release_mouse_capture()
   {

      information() << "windowing_wayland::display::release_mouse_capture";

      auto predicate = [this]()
      {

         synchronous_lock synchronouslock(user_synchronization());

         //display_lock displaylock(Display());

         information() << "XUngrabPointer";

         int_bool bRet = XUngrabPointer(Display(), CurrentTime) != false;

         _on_capture_changed_to(nullptr);

      };

      auto pwindowing = x11_windowing();

      pwindowing->windowing_post(predicate);

      return ::success;

   }


   ::windowing_wayland::windowing * display::x11_windowing()
   {

      return (::windowing_wayland::windowing *) m_pwindowing->m_pWindowing4;

   }


   void display::_on_capture_changed_to(::windowing_wayland::window * pwindowMouseCaptureNew)
   {

      auto pwindowMouseCaptureOld = m_pwindowMouseCapture;

      m_pwindowMouseCapture = pwindowMouseCaptureNew;

      if (pwindowMouseCaptureOld && pwindowMouseCaptureOld != pwindowMouseCaptureNew)
      {

         MESSAGE msg;

         msg.oswindow = pwindowMouseCaptureOld;
         msg.m_atom = e_message_capture_changed;
         msg.wParam = 0;
         msg.lParam = pwindowMouseCaptureNew;

         auto pwindowing = x11_windowing();

         pwindowing->post_ui_message(msg);

      }

   }


   Atom display::intern_atom(const char * pszAtomName, bool bCreate)
   {

      if (m_px11display == nullptr)
      {

         return 0;

      }

      return m_px11display->intern_atom(pszAtomName, bCreate);

   }


   Atom display::intern_atom(::x11::enum_atom eatom, bool bCreate)
   {

      if (eatom < 0 || eatom >= ::x11::e_atom_count)
      {

         return None;

      }

      //Atom atom = m_atoma[eatom];

      //if (atom == None)
      {

         auto atom = intern_atom(atom_name(eatom), bCreate);

         return atom;

         // m_atoma[eatom] = atom;

      }

      //return atom;

   }


   Atom display::_intern_atom_unlocked(const char * pszAtomName, bool bCreate)
   {

      if (m_px11display == nullptr)
      {

         return 0;

      }

      return m_px11display->_intern_atom_unlocked(pszAtomName, bCreate);

   }


   Atom display::_intern_atom_unlocked(::x11::enum_atom eatom, bool bCreate)
   {

      if (eatom < 0 || eatom >= ::x11::e_atom_count)
      {

         return None;

      }

      //Atom atom = m_atoma[eatom];

      //if (atom == None)
      {

         auto atom = _intern_atom_unlocked(atom_name(eatom), bCreate);

         return atom;

         // m_atoma[eatom] = atom;

      }

      //return atom;

   }


   ::e_status display::erase_window(::windowing::window * pwindow)
   {

      return error_failed;

   }


   Atom display::net_wm_state_atom(bool bCreate)
   {

      if (m_atomNetWmState == None)
      {

         m_atomNetWmState = intern_atom(::x11::e_atom_net_wm_state, bCreate);

      }

      return m_atomNetWmState;

   }


   Picture display::xrender_create_picture(::image_pointer pimage)
   {

      Pixmap pixmap = _x11_create_pixmap(pimage);

      if (pixmap == 0)
      {

         return 0;

      }

      auto dpy = Display();

      auto vis = Visual();

      XRenderPictFormat * pformat = XRenderFindVisualFormat(dpy, &vis);

      bool hasAlpha = (pformat->type == PictTypeDirect && pformat->direct.alphaMask);
      int x = 0;
      int y = 0;
      int width = pimage->width();
      int height = pimage->height();

      XRenderPictureAttributes pa = {};

      Picture picture = XRenderCreatePicture(Display(), pixmap, pformat, CPSubwindowMode, &pa);

      return picture;

   }


   ::windowing_wayland::window * display::_get_active_window(::thread * pthread)
   {

      auto window = m_px11display->_get_active_window();

      auto pwindow = _window(window);

      windowing_output_debug_string("::GetActiveWindow 2");

      return pwindow;

   }


   ::windowing_wayland::window * display::get_keyboard_focus()
   {

      return m_pwindowKeyboardFocus;

   }


   ::windowing_wayland::window * display::_get_keyboard_focus()
   {

      auto ppropertyobject = __new(::property_object);

      auto predicate = [this, ppropertyobject]()
      {

         synchronous_lock synchronouslock(user_synchronization());

         oswindow oswindow = nullptr;

         windowing_output_debug_string("::GetFocus 1");

#ifdef display_lock_LOCK_LOG

         b_prevent_display_lock_lock_log = false;

#endif

         //display_lock displaylock(Display());

         windowing_output_debug_string("::GetFocus 1.01");

         Window window = None;

         int revert_to = 0;

         bool bOk = XGetInputFocus(Display(), &window, &revert_to) != 0;

         if (!bOk)
         {

            windowing_output_debug_string("::GetFocus 1.2");

            return;

         }

         if (window == None || window == PointerRoot)
         {

            windowing_output_debug_string("::GetFocus 1.3");

            return;

         }

         ppropertyobject->payload("window") = (::iptr) window;

         windowing_output_debug_string("::GetFocus 2");

      };

      auto pwindowing = x11_windowing();

      //proutine->set_timeout(5_s);

      pwindowing->windowing_send(predicate);

//      if(proutine->has_timed_out())
//      {
//
//         return nullptr;
//
//      }

      if (ppropertyobject->payload("window").is_new())
      {

         return nullptr;

      }

      Window window = (Window) ppropertyobject->payload("window").as_iptr();

      auto pwindow = _window(window);

      if (!pwindow)
      {

         return nullptr;

      }

      return pwindow;

   }


   bool display::get_cursor_position(::point_i32 * ppointCursor)
   {

      Window root_return;
      Window child_return;
      i32 win_x_return;
      i32 win_y_return;
      u32 mask_return;

#ifdef display_lock_LOCK_LOG

      b_prevent_display_lock_lock_log = true;

#endif

      synchronous_lock synchronouslock(user_synchronization());

      windowing_output_debug_string("::GetCursorPos 1");

      //display_lock displaylock(Display());

      XQueryPointer(Display(), DefaultRootWindow(Display()), &root_return, &child_return, &ppointCursor->x(),
                    &ppointCursor->y(), &win_x_return, &win_y_return, &mask_return);

#ifdef display_lock_LOCK_LOG

      b_prevent_display_lock_lock_log = false;

#endif

      windowing_output_debug_string("::GetCursorPos 2");

      return true;

   }


   XImage * display::_x11_create_image(::image_pointer pimage)
   {

      pimage->map();

      char * image32 = (char *) pimage->get_data();

      int width = pimage->width();

      int height = pimage->height();

      int depth = 32; // works fine with depth = 24

      int bitmap_pad = 32; // 32 for 24 and 32 bpp, 16, for 15&16

      int bytes_per_line = pimage->scan_size(); // number of bytes in the client image between the start of one scanline and the start of the next

      XImage * pximage = XCreateImage(Display(), CopyFromParent, depth, ZPixmap, 0, image32, width, height,
                                      bitmap_pad, bytes_per_line);

      return pximage;

   }


   XImage * display::x11_create_image(::image_pointer pimage)
   {

      synchronous_lock synchronouslock(user_synchronization());

      windowing_output_debug_string("::x11_create_image 1");

      //display_lock displaylock(Display());

      return _x11_create_image(pimage);

   }


   Pixmap display::_x11_create_pixmap(::image_pointer pimage)
   {

      if (!pimage)
      {

         return 0;

      }

      XImage * pximage = _x11_create_image(pimage);

      if (pximage == nullptr)
      {

         return 0;

      }

      int depth = 32; // works fine with depth = 24

      Pixmap pixmap = XCreatePixmap(Display(), DefaultRootWindow(Display()), pimage->width(), pimage->height(), depth);

      XGCValues gcvalues = {};

      GC gc = XCreateGC(Display(), pixmap, 0, &gcvalues);

      XPutImage(Display(), pixmap, gc, pximage, 0, 0, 0, 0, pimage->width(), pimage->height());

      XFreeGC(Display(), gc);

      return pixmap;

   }


   Pixmap display::x11_create_pixmap(::image_pointer pimage)
   {

      synchronous_lock synchronouslock(user_synchronization());

      windowing_output_debug_string("::x11_create_pixmap 1");

      //display_lock displaylock(Display());

      return _x11_create_pixmap(pimage);

   }


   comparable_array<Window> display::x11_window_list()
   {

      comparable_array<Window> windowa;

      auto atomWindowList = intern_atom("_NET_CLIENT_LIST_STACKING", False);

      if (atomWindowList == 0)
      {

         atomWindowList = intern_atom("_NET_CLIENT_LIST", False);

      }

      if (atomWindowList == 0)
      {

         return windowa;

      }

      Atom type;
      int form;
      unsigned long remain;
      unsigned char * list;
      unsigned long ulBytesReturned = 0;
      //errno = 0;

      Atom actual_type;

      int actual_format;

      unsigned long int bytes_after;

      Window * windowList = nullptr;

      if (XGetWindowProperty(
         Display(),
         Window(),
         atomWindowList, 0, 1024, False, XA_WINDOW,
         &actual_type, &actual_format, &ulBytesReturned, &bytes_after,
         (unsigned char **) &windowList) != Success)
      {

         information("winlist() -- GetWinProp");

         return windowa;

      }

      unsigned long nchildren = ulBytesReturned / sizeof(Window);

      windowa.set_size(nchildren);

      memcpy(windowa.data(), windowList, minimum(windowa.get_size_in_bytes(), ulBytesReturned));

      XFree(windowList);

      return windowa;

   }


   bool display::point_is_window_origin(::point_i32 pointHitTest, ::windowing::window * pwindowExclude, int iMargin)
   {

      bool bIsOrigin = false;

      auto psystem = acmesystem()->m_papexsystem;

      auto pnode = psystem->node();

      pnode->node_send([this, pointHitTest, pwindowExclude, iMargin, &bIsOrigin]()
                       {

                          ::windowing_wayland::window * pwindowxcbExclude = nullptr;

                          if (pwindowExclude)
                          {

                             pwindowxcbExclude = dynamic_cast < ::windowing_wayland::window * >(pwindowExclude);

                          }

                          synchronous_lock synchronouslock(user_synchronization());

                          windowing_output_debug_string("::GetFocus 1");

#ifdef display_lock_LOCK_LOG

                          b_prevent_display_lock_lock_log = false;

#endif

                          if (!Display())
                          {

                             windowing_output_debug_string("::GetFocus 1.1");

                             return;

                          }

                          //display_lock displaylock(Display());

                          windowing_output_debug_string("::GetFocus 1.01");

                          auto windowa = x11_window_list();

                          ::rectangle_i32 rectangleTest;

                          for (index i = 0; i < windowa.get_size(); i++)
                          {

                             string strItem = ::x11_get_name(Display(), windowa[i]);

                             ::rectangle_i32 rectangleHigher;

                             if (::is_set(pwindowxcbExclude) && windowa[i] == pwindowxcbExclude->Window())
                             {

                                continue;

                             }

                             if (::x11_get_window_rect(Display(), windowa[i], &rectangleHigher))
                             {

                                ::rectangle_i32 rectangleHitTest;

                                rectangleHitTest.set(rectangleHigher.origin(), ::size_i32());

                                rectangleHitTest.inflate(iMargin + 1);

                                if (rectangleHitTest.contains(pointHitTest))
                                {

                                   bIsOrigin = true;

                                   return;

                                }

                             }

                          }

                       });

      return bIsOrigin;

   }



   wayland_buffer display::create_wayland_buffer(const ::size_i32 & size)
   {
      struct wl_shm_pool *pool;
      int stride = size.cx() * 4; // 4 bytes per pixel
      int strided_area = stride * size.cy();
      int fd;
      struct wl_buffer *buff;

      fd = os_create_anonymous_file(strided_area);
      if (fd < 0) {
         fprintf(stderr, "creating a buffer file for %d B failed: %m\n",
                 size);
         exit(1);
      }

      void * shm_data = mmap(NULL, strided_area, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);
      if (shm_data == MAP_FAILED) {
         fprintf(stderr, "mmap failed: %m\n");
         close(fd);
         exit(1);
      }

      pool = wl_shm_create_pool(m_pwlshm, fd, size);
      buff = wl_shm_pool_create_buffer(pool, 0,
                                       size.cx(), size.cy(),
                                       stride,
                                       WL_SHM_FORMAT_XRGB8888);
      //wl_buffer_add_listener(buffer, &buffer_listener, buffer);
      wl_shm_pool_destroy(pool);
      return buff;
   }


   wayland_buffer display::create_wayland_buffer(::image * pimage)
   {

      auto waylandbuffer = create_wayland_buffer(pimage->size());

      pimage->map();

      copy_image32((::image32_t*)waylandbuffer.m_pdata, pimage->size(), pimage->width() * 4, pimage->data(), pimage->scan_size());

      return waylandbuffer;

   }

} // namespace windowing_wayland



