//
// Created by camilo on 2024-05-26 22:03 <3ThomasBorregaardSorensen!!
//
#include "framework.h"
#include "windowing_system.h"
#include "node.h"
#include "acme/nano/nano.h"
#include "acme/nano/user/user.h"
#include "acme/parallelization/manual_reset_event.h"
#include "acme/platform/node.h"
#include "acme/platform/system.h"
//#include <X11/Xatom.h>
//#include <xkbcommon/xkbcommon.h>
//#include <X11/XKBlib.h>
//#include <X11/Xutil.h>
//#include <gdk/gdkx.h>

//namespace x11
//////{

   namespace node_gdk
   {

   windowing_system::windowing_system()
   {

//      m_pvoidX11Display = nullptr;
  ///    m_estatusInitializeX11 = error_not_initialized;

   }


   windowing_system::~windowing_system()
   {


   }


//   ::e_status windowing_system::defer_initialize_windowing_system()
//   {
//
////      if (m_estatusInitializeX11 == error_not_initialized) {
////
////         m_estatusInitializeX11 = initialize_windowing_system();
////
////      }
////
////      return m_estatusInitializeX11;
//
//      return ::success;
//
//   }
//
//
//   ::e_status windowing_system::initialize_windowing_system()
//   {
//
////      informationf("node_gtk3::node::x11_initialize");
////
////      informationf("node_gtk3::node::x11_initialize going to call x11_init_threads");
////
////      if (!nano()->user()->init_threads()) {
////
////         return ::error_failed;
////
////      }
////
////      // gdk_x11 does error handling?!?!?!
////      //XSetErrorHandler(_c_XErrorHandler);
////
////      //g_pmutexX11 = new ::pointer < ::mutex >();
//
//      return ::success;
//
//   }


//   void *windowing_system::get_display()
//   {
//
//      //return ::acme::node::x11_get_display();
//
//      defer_initialize_windowing_system();
//
//      if (m_pvoidX11Display == NULL) {
//
//         m_pvoidX11Display = this->fetch_windowing_system_display();
//
//      }
//
//      return m_pvoidX11Display;
//
//   }


   void windowing_system::sync(const ::procedure &procedure)
   {

      if (::is_main_thread()) {

         procedure();

         return;

      }

      //__matter_send_procedure(this, this, &node::node_post, procedure);

//      CLASS_DECL_ACME bool main_synchronous(const class time & time, const ::procedure & function)
//      {

      auto pevent = ::place(new manual_reset_event());

      user_post([procedure, pevent]
                {

                   procedure();

                   pevent->SetEvent();

                });

      if (!pevent->wait(procedure.m_timeTimeout)) {

         throw ::exception(error_timeout);
         //pevent.release();

         //return false;

      }

      ///return true;
//
//      }


   }


//   void windowing_system::async(const ::procedure &procedure)
//   {
//
//      node()->windowing_system_async(procedure);
//
//   }

//
//   void windowing_system::display_error_trap_push(int i)
//   {
//
//
//      node()->windowing_system_display_error_trap_push(i);
//
////      if(system()->m_ewindowing == e_windowing_x11)
////      {
////
////         GdkDisplay *gdkdisplay;
////
////         gdkdisplay = gdk_display_get_default ();
////         gdk_x11_display_error_trap_push (gdkdisplay);
////
////      }
//
//   }
//
//
//   void windowing_system::display_error_trap_pop_ignored(int i)
//   {
//
//      node()->windowing_system_display_error_trap_pop_ignored(i);
////      if(system()->m_ewindowing == e_windowing_x11)
////      {
////
////         GdkDisplay *gdkdisplay;
////         gdkdisplay = gdk_display_get_default ();
////         gdk_x11_display_error_trap_pop_ignored (gdkdisplay);
////
////      }
//
//   }
//

//
//    void node::sync(const ::procedure & procedure)
//    {
//
//        nano()->user()->x11_sync(procedure);
//
//    }
//
//
//    void node::async(const ::procedure & procedure)
//    {
//
//        nano()->user()->x11_async(procedure);
//
//    }
//
//
//    void node::display_error_trap_push(int i)
//    {
//
//
//    }
//
//
//    void node::display_error_trap_pop_ignored(int i)
//    {
//
//
//    }


//   void *windowing_system::fetch_windowing_system_display()
//   {
//
//      GdkDisplay *gdkdisplay;
//
//      gdkdisplay = gdk_display_get_default();
//
//      void *pvoidX11Display = gdk_x11_display_get_xdisplay(gdkdisplay);
//
//      printf("Got this Display from gdk_x11 display : %lX", (::uptr) pvoidX11Display);
//
//      return pvoidX11Display;
//
//   }


   void windowing_system::async(const ::procedure &procedure)
   {

      m_pgdknode->_gdk_branch(procedure);

   }


//   void windowing_system::display_error_trap_push(int i)
//   {
//
//      if (system()->m_ewindowing == e_windowing_x11) {
//
//         GdkDisplay *gdkdisplay;
//
//         gdkdisplay = gdk_display_get_default();
//         gdk_x11_display_error_trap_push(gdkdisplay);
//
//      }
//
//   }
//
//
//   void windowing_system::display_error_trap_pop_ignored(int i)
//   {
//
//      if (system()->m_ewindowing == e_windowing_x11) {
//
//         GdkDisplay *gdkdisplay;
//         gdkdisplay = gdk_display_get_default();
//         gdk_x11_display_error_trap_pop_ignored(gdkdisplay);
//
//      }
//
//   }

} // namespace node_gdk

//} // namespace x11



