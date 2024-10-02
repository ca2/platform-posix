// created by Camilo <3CamiloSasukeThomasBorregaardSoerensen
// recreated by Camilo 2021-01-28 22:20 <3TBS, Mummi and bilbo!!
// hi5 contribution...
#include "framework.h"
#include "buffer.h"
#include "keyboard.h"
#include "window.h"
#include "windowing.h"
#include "windowing.h"
#include "display.h"
#include "cursor.h"
#include "acme/constant/message.h"
#include "acme/operating_system/a_system_menu.h"
#include "acme/parallelization/synchronous_lock.h"
#include "acme/prototype/geometry2d/_text_stream.h"
#include "acme/user/user/_text_stream.h"
#include "apex/platform/node.h"
#include "apex/platform/system.h"
#include "aura/graphics/graphics/graphics.h"
#include "aura/message/user.h"
#include "aura/user/user/interaction_graphics_thread.h"
#include "aura/user/user/interaction_impl.h"
#include "aura/platform/message_queue.h"
#include "aura_posix/node.h"
//#include <X11/Xatom.h>
//#include <X11/extensions/sync.h>
#include <wayland-client.h>
//#include <gdk/gdkwindow.h>
#include <linux/input.h> // for BTN_LEFT,...
#include <xkbcommon/xkbcommon.h>
//#include <gio/gio.h>
//#include "app-core/gcom/backimpact/visual_effect.h"
#include "aura/graphics/image/context.h"
#include "aura/graphics/image/drawing.h"
#include "aura/platform/application.h"
#include "windowing_system_wayland/xfree86_key.h"


#include <gtk/gtk.h>
#include <X11/Xlib.h>


//
// enum xdg_toplevel_resize_edge {
//    XDG_TOPLEVEL_RESIZE_EDGE_NONE = 0,
//    XDG_TOPLEVEL_RESIZE_EDGE_TOP = 1,
//    XDG_TOPLEVEL_RESIZE_EDGE_BOTTOM = 2,
//    XDG_TOPLEVEL_RESIZE_EDGE_LEFT = 4,
//    XDG_TOPLEVEL_RESIZE_EDGE_TOP_LEFT = 5,
//    XDG_TOPLEVEL_RESIZE_EDGE_BOTTOM_LEFT = 6,
//    XDG_TOPLEVEL_RESIZE_EDGE_RIGHT = 8,
//    XDG_TOPLEVEL_RESIZE_EDGE_TOP_RIGHT = 9,
//    XDG_TOPLEVEL_RESIZE_EDGE_BOTTOM_RIGHT = 10,
// };
//

// xdg_toplevel_resize_edge as_xdg_toplevel_resize_edge(enum_window_edge eedge)
// {
//
//    switch(eedge)
//    {
//       case e_window_edge_south: return XDG_TOPLEVEL_RESIZE_EDGE_BOTTOM;
//       case e_window_edge_south_west: return XDG_TOPLEVEL_RESIZE_EDGE_BOTTOM_LEFT;
//       case e_window_edge_south_east: return XDG_TOPLEVEL_RESIZE_EDGE_BOTTOM_RIGHT;
//       case e_window_edge_west: return XDG_TOPLEVEL_RESIZE_EDGE_LEFT;
//       case e_window_edge_east: return XDG_TOPLEVEL_RESIZE_EDGE_RIGHT;
//       case e_window_edge_north_west: return XDG_TOPLEVEL_RESIZE_EDGE_TOP_LEFT;
//       case e_window_edge_north_east: return XDG_TOPLEVEL_RESIZE_EDGE_TOP_RIGHT;
//       case e_window_edge_north: return XDG_TOPLEVEL_RESIZE_EDGE_TOP;
//       default: return XDG_TOPLEVEL_RESIZE_EDGE_NONE;
//    }
//
// }



//#include "acme/operating_system/x11/display_lock.h"

//#define GdkWindowEdgeNone ((GdkWindowEdge)-1)
//void on_sn_launch_context(void * pSnContext, Window window);

void on_sn_launch_complete(void* pSnContext);


::particle* user_synchronization();


#undef ALOG_CONTEXT
#define ALOG_CONTEXT ::trace_object(::trace_category_windowing)


namespace windowing_gtk4
{
   //::string _gtk_get_resize_cursor_name(enum_window_edge eedge);
   // Function to update the theme based on the system preference
   static void update_theme_based_on_system(GtkSettings *settings, gpointer user_data) {
      gboolean prefer_dark_theme;
      g_object_get(settings, "gtk-application-prefer-dark-theme", &prefer_dark_theme, NULL);

      if (prefer_dark_theme) {
         g_print("System prefers dark theme.\n");
      } else {
         g_print("System prefers light theme.\n");
      }
   }

   window::window()
   {
      //m_bXShmPutImagePending = false;
      //m_bXShmComplete = false;
      m_pWindow4 = this;
      resizing = false;
      moving = false;

      // m_windowbuttonpresseda[0].m_pwindow = this;
      // m_windowbuttonpresseda[0].m_pszName = "move";
      // m_windowbuttonpresseda[1].m_pwindow = this;
      // m_windowbuttonpresseda[1].m_pszName = "size";
      //m_bNetWmStateHidden = false;
      //m_bNetWmStateMaximized = false;
      //m_bNetWmStateFocused = false;

      //      for (auto & i : m_iaNetWmState)
      //      {
      //
      //         i = -1;
      //
      //      }

      //m_cursorLast = 0;

      m_htask = 0;

      //m_window = None;

      //m_puserinteractionimpl = nullptr;

      //m_bMessageOnlyWindow = false;

      //zero(m_visual);

      //m_iDepth = -1;

      //m_iScreen = -1;

      //m_colormap = None;

      //m_iXic = 0;
      m_bPendingStartMove = false;

   }


   window::~window()
   {
   }

   void window::_set_oswindow(::oswindow oswindow)
   {
   }

   ::oswindow window::oswindow() const
   {
      return (::oswindow)this;
   }

   //
   // // Callback function for Option 1 click
   // static void on_option1_clicked(GtkButton *button, gpointer user_data) {
   //    g_print("Option 1 clicked!\n");
   // }


   //
   // // Callback function for Option 1 menu item
   // static void on_option1_activate(GtkMenuItem *menuitem, gpointer user_data) {
   //    g_print("Option 1 selected from context menu!\n");
   // }
   //
   // // Callback function for Option 2 menu item
   // static void on_option2_activate(GtkMenuItem *menuitem, gpointer user_data) {
   //    g_print("Option 2 selected from context menu!\n");
   // }
   //
   //
   // // Function to create and show the context menu
   // static void show_context_menu(GtkWidget *widget, GdkEvent *event, gdouble x, gdouble y) {
   //    GtkWidget *menu;
   //    GtkWidget *menu_item1, *menu_item2;
   //
   //    // Create a menu
   //    menu = gtk_menu_new();
   //
   //    // Create Option 1 menu item and connect it to the callback
   //    menu_item1 = gtk_menu_item_new_with_label("Option 1");
   //    g_signal_connect(menu_item1, "activate", G_CALLBACK(on_option1_activate), NULL);
   //    gtk_menu_shell_append(GTK_MENU_SHELL(menu), menu_item1);
   //
   //    // Create Option 2 menu item and connect it to the callback
   //    menu_item2 = gtk_menu_item_new_with_label("Option 2");
   //    g_signal_connect(menu_item2, "activate", G_CALLBACK(on_option2_activate), NULL);
   //    gtk_menu_shell_append(GTK_MENU_SHELL(menu), menu_item2);
   //
   //    // Show all menu items
   //    gtk_widget_show(menu_item1);
   //    gtk_widget_show(menu_item2);
   //
   //    // Popup the menu at the right-click location
   //    gtk_menu_popup_at_pointer(GTK_MENU(menu), event);
   // }
   //


   // Callback for when Option 1 is selected from the popover menu
   static void on_option1_activated(GSimpleAction *action, GVariant *parameter, gpointer user_data) {
      g_print("Option 1 selected from popover menu!\n");
   }

   // Callback for when Option 2 is selected from the popover menu
   static void on_option2_activated(GSimpleAction *action, GVariant *parameter, gpointer user_data) {
      g_print("Option 2 selected from popover menu!\n");
   }



   // static void
// on_move_button_clicked (
//   GtkButton* self,
//   gpointer user_data
// )
//    {
//
//       print_line("on_move_button_clicked");
//    }

   static void clear_controllers(GtkWidget *widget) {
      // Retrieve the list of all controllers attached to the widget
      GListModel *controllers = gtk_widget_observe_controllers(widget);

      guint n_items = g_list_model_get_n_items(controllers);

      g_print("Listing %d items from the GListModel:\n", n_items);
      for (guint i = 0; i < n_items; i++)
      {
         auto *item = (GObject *)  g_list_model_get_item(controllers, i);
         if (G_IS_OBJECT(item))
         {
            GtkEventController *controller = GTK_EVENT_CONTROLLER(item);
            gtk_widget_remove_controller(widget, controller);
            g_print("Item %d: %s\n", i, G_OBJECT_TYPE_NAME(item));
         }
         g_object_unref(item); // Unreference the item after retrieving it
      }

      // Free the list after use
      g_object_unref(controllers);
   }

   void window::_on_initialize_system_menu_button(GtkWidget * pbutton, const ::scoped_string & scopedstrAtom)
   {

//       if(scopedstrAtom == "Move")
//       {
//
//          auto p = gtk_widget_get_first_child(pbutton);
//          GObject *objectMenuSectionBox = G_OBJECT(p);
//          GType typeMenuSectionBox = G_OBJECT_TYPE (objectMenuSectionBox);
//          const char *type_nameMenuSectionBox = g_type_name(typeMenuSectionBox);
//
// //         auto p2 = gtk_widget_get_first_child(p);
//   //       GObject *object2 = G_OBJECT(p2);
//     //     GType type2 = G_OBJECT_TYPE (object2);
//       //   const char *type_name2 = g_type_name(type2);
//          clear_controllers(p);
//          // // Create a gesture fo)r button presses (GtkGestureClick)
//          GtkGesture *gesture = gtk_gesture_click_new();
//          gtk_gesture_single_set_button(GTK_GESTURE_SINGLE(gesture), 0); // Left mouse button
//          g_signal_connect(gesture, "pressed", G_CALLBACK(on_move_button_pressed), this);
//          //
//          // // Add the gesture to the menu button
//          gtk_widget_add_controller(GTK_WIDGET(p), GTK_EVENT_CONTROLLER(gesture));
//
//           //g_signal_connect(pbutton, "clicked", G_CALLBACK(on_move_button_clicked), this);
//       }
//
//       else if(scopedstrAtom == "size")
//       {
//
//       }

   }

   // // Function to copy CSS style from one button to another
   // void copy_button_style(GtkWidget *source_button, GtkWidget *target_button) {
   //    // Get the style context of the source button
   //    GtkStyleContext *source_context = gtk_widget_get_style_context(source_button);
   //
   //    // Create a CSS provider to apply to the target button
   //    GtkCssProvider *css_provider = gtk_css_provider_new();
   //
   //    // Define a buffer to hold the style string
   //    GString *style_string = g_string_new("");
   //
   //    // Get properties from the source button's style context
   //    GdkRGBA bg_color;
   //    gtk_style_context_get_color(source_context, GTK_STATE_FLAG_NORMAL, &bg_color);
   //    g_string_append_printf(style_string, "background-color: rgba(%d, %d, %d, %.2f);",
   //                           (int)(bg_color.red * 255), (int)(bg_color.green * 255),
   //                           (int)(bg_color.blue * 255), bg_color.alpha);
   //
   //    // Apply the generated CSS to the CSS provider
   //    gtk_css_provider_load_from_data(css_provider, style_string->str, -1);
   //
   //    // Get the style context of the target button
   //    GtkStyleContext *target_context = gtk_widget_get_style_context(target_button);
   //
   //    // Apply the CSS provider to the target button
   //    gtk_style_context_add_provider(target_context, GTK_STYLE_PROVIDER(css_provider),
   //                                   GTK_STYLE_PROVIDER_PRIORITY_USER);
   //
   //    // Free resources
   //    g_object_unref(css_provider);
   //    g_string_free(style_string, TRUE);
   // }


   void window::defer_show_system_menu(::user::mouse *pmouse)
   {

      ::gtk4::nano::user::window::defer_show_system_menu(pmouse);
//       // Function to create and show the popup menu
//
//       //    // Create a popover menu
//       //    auto popover = gtk_popover_new();
//       //    //gtk_popover_set_pointing_to(GTK_POPOVER(popover), &(GdkRectangle){x, y, 1, 1});
//       // GdkRectangle r;
//       // r.width = 16;
//       // r.height = 16;
//       // r.x = x-r.width/2;
//       // r.y = y-r.height/2;
//       // // Show the popover relative to the drawing area
//       // gtk_popover_set_pointing_to(GTK_POPOVER(popover), &r);
//       // gtk_popover_set_position(GTK_POPOVER(popover), GTK_POS_BOTTOM);
//       //
//       //
//       //    // Create a box to hold the menu items
//       //    auto*  box = gtk_box_new(GTK_ORIENTATION_VERTICAL, 0);
//       //    gtk_box_set_homogeneous(GTK_BOX(box), FALSE);
//       //
//       //    // Create Option 1 button and connect it to the on_option1_clicked callback
//       //    auto * menu_item1 = gtk_button_new_with_label("Option 1");
//       //    gtk_box_append(GTK_BOX(box), menu_item1);
//       //    g_signal_connect(menu_item1, "clicked", G_CALLBACK(on_option1_clicked), NULL);
//       //
//       //    // Create Option 2 button (no callback in this case)
//       //    auto* menu_item2 = gtk_button_new_with_label("Option 2");
//       //    gtk_box_append(GTK_BOX(box), menu_item2);
//       //
//       //    // Add the box to the popover
//       //    gtk_popover_set_child(GTK_POPOVER(popover), box);
//       //
//       // gtk_widget_set_parent(popover, m_pdrawingarea);
//       //    // Show the popover
//       //    gtk_popover_popup(GTK_POPOVER(popover));
//
//       // Create and show the popover menu at the click location
//
//       auto * widget = m_pdrawingarea;
//       int x = pmouse->m_pointAbsolute.x();
//       int y = pmouse->m_pointAbsolute.y();
//
//
//       gtk_widget_realize(m_pgtkwidget);
//
//       auto *pmenu = _create_system_menu();
//
//       auto ppopover = gtk_popover_menu_new_from_model(G_MENU_MODEL(pmenu));
//       auto pbox = gtk_widget_get_first_child(ppopover);
//
//             GObject *objectContent = G_OBJECT(pbox);
//       GType typeContent = G_OBJECT_TYPE (objectContent);
//       const char *type_nameContent = g_type_name(typeContent);
//
//       GtkWidget * abuttontemplate=nullptr;
//       GtkWidget * abuttontemplatechild=nullptr;
//
//       auto p = pbox;
//
//       while(p!=nullptr)
//       {
//          auto pobject = G_OBJECT(p);
//          GType type = G_OBJECT_TYPE (pobject);
//          const char *type_name = g_type_name(type);
//          if(g_strcmp0(type_name, "GtkModelButton") == 0)
//          {
//             break;
//          }
//          p=gtk_widget_get_first_child(p);
//       }
//
//
//       if(p)
//       {
//
//          auto pbutton = GTK_WIDGET(p);
//
//          if(pbutton)
//          {
//
//             abuttontemplate = pbutton;
//             abuttontemplatechild = gtk_widget_get_first_child(pbutton);
//
//          }
//
//       }
//
//
//
// //       if(g_strcmp0(type_nameContent, "GtkPopoverContent") == 0)
// //       {
// //          auto pmenuScrolledWindow = gtk_widget_get_first_child(pbox);
// //
// //          GObject *objectScrolledWindow = G_OBJECT(pmenuScrolledWindow);
// //          GType typeScrolledWindow = G_OBJECT_TYPE (objectScrolledWindow);
// //          const char *type_nameScrolledWindow = g_type_name(typeScrolledWindow);
// //
// //          if(g_strcmp0(type_nameScrolledWindow, "GtkScrolledWindow") == 0)
// //          {
// //             auto pmenuViewPort = gtk_widget_get_first_child(pmenuScrolledWindow);
// //
// //             GObject *objectViewPort = G_OBJECT(pmenuViewPort);
// //             GType typeViewPort = G_OBJECT_TYPE (objectViewPort);
// //             const char *type_nameViewPort = g_type_name(typeViewPort);
// //
// //             if(g_strcmp0(type_nameViewPort, "GtkViewport") == 0)
// //             {
// //
// //                auto pmenuStack = gtk_widget_get_first_child(pmenuViewPort);
// //
// //                GObject *objectStack = G_OBJECT(pmenuStack);
// //                GType typeStack = G_OBJECT_TYPE (objectStack);
// //                const char *type_nameStack = g_type_name(typeStack);
// //
// //                if(g_strcmp0(type_nameStack, "GtkStack") == 0)
// //                {
// //
// //                   auto pmenuMenuSectionBox = gtk_widget_get_first_child(pmenuStack);
// //
// //                   GObject *objectMenuSectionBox = G_OBJECT(pmenuMenuSectionBox);
// //                   GType typeMenuSectionBox = G_OBJECT_TYPE (objectMenuSectionBox);
// //                   const char *type_nameMenuSectionBox = g_type_name(typeMenuSectionBox);
// //
// //                   if(g_strcmp0(type_nameMenuSectionBox, "GtkMenuSectionBox") == 0)
// //                   {
// //                      auto pmenuBox = gtk_widget_get_first_child(pmenuMenuSectionBox);
// //
// //                      GObject *objectBox = G_OBJECT(pmenuBox);
// //                      GType typeBox = G_OBJECT_TYPE (objectBox);
// //                      const char *type_nameBox = g_type_name(typeBox);
// //
// //                      if(g_strcmp0(type_nameBox, "GtkBox") == 0)
// //                      {
// //
// //                         auto pmenuMenuSectionBox = gtk_widget_get_first_child(pmenuBox);
// //
// //                         GObject *objectMenuSectionBox = G_OBJECT(pmenuMenuSectionBox);
// //                         GType typeMenuSectionBox = G_OBJECT_TYPE (objectMenuSectionBox);
// //                         const char *type_nameMenuSectionBox = g_type_name(typeMenuSectionBox);
// //
// //                         if(g_strcmp0(type_nameMenuSectionBox, "GtkMenuSectionBox") == 0)
// //                         {
// //
// //                            auto pmenuBox = gtk_widget_get_first_child(pmenuMenuSectionBox);
// //                            auto pmenuFirstItem = gtk_widget_get_first_child(pmenuBox);
// //
// //                            auto pmenuItem = pmenuFirstItem;
// //
// //                            while(pmenuItem != nullptr)
// //                            {
// //
// //                               GObject *objectItem = G_OBJECT(pmenuItem);
// //                               GType typeItem = G_OBJECT_TYPE (objectItem);
// //                               const char *type_nameItem = g_type_name(typeItem);
// //
// //                               if(g_strcmp0(type_nameItem, "GtkModelButton") == 0)
// //                               {
// //
// //                                  auto pbutton = GTK_WIDGET(objectItem);
// //
// //                                  if(pbutton)
// //                                  {
// //
// //                                     gchar * text =nullptr;
// //
// //                                     g_object_get(objectItem, "text", &text, NULL);
// // //                                    auto pName= gtk_button_get_label(pbutton);
// //                                     ::string strName(text);
// //                                     g_free(text);
// //
// //                                     int iFind = m_straSystemMenuName.find_first(strName);
// //
// //                                     if(iFind >= 0)
// //                                     {
// //
// //                                        ::string strAtom = m_straSystemMenuAtom[iFind];
// //
// //                                        if(strAtom.is_empty())
// //                                        {
// //
// //                                           //_on_initialize_system_menu_button(pbutton, strName);
// //
// //                                        }
// //                                        else
// //                                        {
// //
// //                                           if(!abuttontemplate)
// //                                           {
// //
// //                                              abuttontemplate = pbutton;
// //                                              abuttontemplatechild = gtk_widget_get_first_child(pbutton);
// //                                           }
// //                                           _on_initialize_system_menu_button(pbutton, strAtom);
// //
// //                                        }
// //
// //                                     }
// //
// //                                  }
// //
// //
// //                               }
// //
// //                               pmenuItem = gtk_widget_get_next_sibling(pmenuItem);
// //
// //                            }
// //
// //                            //print_line(type_nameFirstItem);
// //
// //                         }
// //
// //                      }
// //
// //                   }
// //
// //                }
// //
// //             }
// //
// //          }
// //
// //       }
//
//
//       //    // Create Option 1 button and connect it to the on_option1_clicked callback
//       //     auto * menu_item1 = gtk_button_new_with_label("Option 1");
//       // gtk_popover_menu_add_child(GTK_POPOVER_MENU(ppopover), GTK_WIDGET(menu_item1), "move");
//       // //    gtk_box_append(GTK_BOX(box), menu_item1);
//       // //    g_signal_connect(menu_item1, "clicked", G_CALLBACK(on_option1_clicked), NULL);
//       // //
//       // //    // Create Option 2 button (no callback in this case)
//       //     auto* menu_item2 = gtk_button_new_with_label("Option 2");
//       // gtk_popover_menu_add_child(GTK_POPOVER_MENU(ppopover), GTK_WIDGET(menu_item1), "size");
//       // //    gtk_box_append(GTK_BOX(box), menu_item2);
//
//
//       // auto ppopover = gtk_popover_new();
//       //
//       // //auto pbox = gtk_box_layout_new(GTK_ORIENTATION_VERTICAL);
//       //
//       // //gtk_widget_set_layout_manager(ppopover,pbox);
//       //
//       // // Create a vertical box layout for the popover content
//       // GtkWidget *pbox = gtk_box_new(GTK_ORIENTATION_VERTICAL, 5);
//       //
//       // // Create buttons to add to the popover
//       //
//       // GtkWidget *button2 = gtk_button_new_with_label("Option 2");
//       // GtkWidget *button3 = gtk_button_new_with_label("Option 3");
//       //
//       // // Connect signals for each button
//       //
//       // //g_signal_connect(button2, "clicked", G_CALLBACK(on_button_clicked), "Option 2");
//       // //g_signal_connect(button3, "clicked", G_CALLBACK(on_button_clicked), "Option 3");
//       //
//       // // Add buttons to the box
//       //
//       // //gtk_box_append(GTK_BOX(box), button2);
//       // //gtk_box_append(GTK_BOX(box), button3);
//       // // Create a CSS provider
//        GtkCssProvider *provider = gtk_css_provider_new();
//       //
//       // // Load CSS data to remove the border and padding from the button
//        gtk_css_provider_load_from_string(provider,
//            "button {"
//            //"  border-width: 0;"
//            //"  padding-left: 8px;"
//            //"  background-color: rgba(0, 0, 0, 0.0);"
//            "  transition: none;"
//            "}");
//
//       // // Apply the CSS to the button's style context
//       //
//       int iWindowButtonPress = 0;
//        for(auto pitem : *m_psystemmenu)
//        {
//           ::string strAtom = pitem->m_strAtom;
//           ::string strName = pitem->m_strName;
//
//           if(strAtom.begins_eat("***"))
//           {
//              auto pbutton = subclassed_model_button_new();
//
//              gtk_button_set_label(GTK_BUTTON(pbutton), strName);
//
//              //gtk_menu_button_set_label(GTK_MENU_BUTTON(pbutton), strName);
//              //g_signal_connect(button1, "clicked", G_CALLBACK(on_button_clicked), "Option 1");
//              //gtk_widget_set_visible(pmenubutton, true);
// //             auto * menu_item1 = gtk_button_new_with_label("Option 1");
//              //copy_button_style(abuttontemplate, pbutton);
//              auto plabel = gtk_button_get_child(GTK_BUTTON(pbutton));
//
//
//
//              auto ppTemplate = gtk_widget_get_css_classes(abuttontemplate);
//              gtk_widget_set_css_classes(GTK_WIDGET(pbutton), (const char **) ppTemplate);
//              // auto ppT = gtk_widget_get_css_name(abuttontemplate);
//              // auto pOld = gtk_widget_get_css_name(GTK_WIDGET(pbutton));
//              // g_object_set(pbutton, "css-name", ppT, NULL);
//              // auto pNew = gtk_widget_get_css_name(GTK_WIDGET(pbutton));
//
//              auto ppTemplateChild = gtk_widget_get_css_classes(abuttontemplatechild);
//              gtk_widget_set_css_classes(plabel, (const char **) ppTemplateChild);
//              // auto ppTC = gtk_widget_get_css_name(abuttontemplatechild);
//              // auto pLOld = gtk_widget_get_css_name(plabel);
//              // g_object_set(plabel, "css-name", ppTC, NULL);
//              // auto pLNew = gtk_widget_get_css_name(plabel);
//
//              //GtkStyleContext *context = gtk_widget_get_style_context(pbutton);
//              //gtk_style_context_add_provider(context, GTK_STYLE_PROVIDER(provider), GTK_STYLE_PROVIDER_PRIORITY_USER);
//              //gtk_widget_set_hexpand(pbutton, TRUE);
//
//              // Get the label from the button
//              //m_windowbuttonpresseda[iWindowButtonPress].m_pwidget = pbutton;
//              pitem->m_pWidgetImpl = GTK_WIDGET(pbutton);
//              GtkGesture *gesture = gtk_gesture_click_new();
//              gtk_gesture_single_set_button(GTK_GESTURE_SINGLE(gesture), 1); // Left mouse button
//              g_signal_connect(gesture, "pressed", G_CALLBACK(on_window_button_pressed), pitem.m_p);
//              //g_signal_connect(gesture, "released", G_CALLBACK(on_window_button_released), m_windowbuttonpresseda + iWindowButtonPress);
//              //
//              // // Add the gesture to the menu button
//              gtk_widget_add_controller(GTK_WIDGET(pbutton), GTK_EVENT_CONTROLLER(gesture));
//
//
//              // Set the horizontal alignment of the label to the left
//              gtk_widget_set_halign(plabel, GTK_ALIGN_START);
//
//              gtk_popover_menu_add_child(GTK_POPOVER_MENU(ppopover), GTK_WIDGET(pbutton), strAtom);
//            //  gtk_box_append(GTK_BOX(pbox), pbutton);
//              iWindowButtonPress++;
//           }
//           // if(iWindowButtonPress >= (sizeof(m_windowbuttonpresseda)/sizeof(m_windowbuttonpresseda[0])))
//           // {
//           //
//           //    break;
//           //
//           // }
//        }
//       //
//       // //gtk_widget_set_parent(GTK_WIDGET(pbox), ppopover);
//       //
//       // gtk_popover_set_child(GTK_POPOVER(ppopover), pbox);
//
//       //g_object_unref(pmenu);
//
//
//       GdkRectangle r;
//       r.width = 16;
//       r.height = 16;
//       r.x = x-r.width/2;
//       r.y = y-r.height/2;
//
//       gtk_popover_set_has_arrow(GTK_POPOVER(ppopover), false);
//
//       gtk_popover_set_pointing_to(GTK_POPOVER(ppopover), &r);
//
//       //gtk_popover_set_offset(GTK_POPOVER(ppopover), x + r.width, y + r.height);
//
//       gtk_popover_set_position(GTK_POPOVER(ppopover), GTK_POS_BOTTOM);
//
//       //gtk_widget_set_parent(ppopover, m_pdrawingarea);
//
//       gtk_widget_set_parent(ppopover, m_pgtkwidget);
//
//       //int min_height = 100;
//
//       //
//
//       gtk_popover_present(GTK_POPOVER(ppopover));
//
//
//       //
//       //
//       //
//       int min_width = 250, width = 250;
//       int min_height = 100, height = 100;
//       gtk_widget_set_size_request(ppopover, 250, min_height);
//       // gtk_widget_realize(pmenuContent);
//        gtk_widget_measure(pbox, GTK_ORIENTATION_HORIZONTAL, -1, &min_width, &width, NULL, NULL);
//        width +=100;
//        gtk_widget_measure(pbox, GTK_ORIENTATION_VERTICAL, width, &min_height, &height, NULL, NULL);
//       GtkAllocation allocation = { 0, 0, width, height };
//       gtk_widget_size_allocate(pbox, &allocation, -1);
//       // //if(height > min_height)
//        {
//
//           gtk_widget_set_size_request(pbox, (double) width * 1.08, (double) height * 1.08);
//           gtk_widget_set_size_request(ppopover, (double) width * 1.15, (double) height * 1.15);
//        }
//
//
//
//
//
//
//
//
//
//
//
//
//       //gtk4_widget w;
//       //w.m_pgtkwidget = ppopover;
//       //w._force_layout();
//       //gtk_popover_menu_set_flags (GTK_POPOVER_MENU(ppopover), 0      );
//
//
//
//       gtk_popover_popup(GTK_POPOVER(ppopover));
//
//
//       gtk_widget_queue_draw(m_pgtkwidget);
//
//       //m_puserinteractionimpl->m_puserinteraction->set_need_redraw();
//
//       //m_puserinteractionimpl->m_puserinteraction->post_redraw();
//
//       //gtk_popover_present(GTK_POPOVER(ppopover));
//
//
//       // GtkWidget *drawing_area = GTK_WIDGET(m_pdrawingarea);
//       // GdkEvent *event = gtk_gesture_get_last_event(GTK_GESTURE(m_pgtkgestureClick), NULL);
//       // show_context_menu(drawing_area, event, x, y); // Show the context menu at the click location

   }

   // Callback function to draw on the drawing area
   static gboolean on_draw_event(GtkWidget* widget, cairo_t* cr, gpointer p)
   {
      auto pwindow = (::windowing_gtk4::window *)p;
      pwindow->_on_cairo_draw(widget, cr);
      return FALSE;
   }



   void window::_on_cairo_draw(GtkWidget* widget, cairo_t* cr)
   {

      if(!m_puserinteractionimpl
         || !m_puserinteractionimpl->m_puserinteraction)
      {

         return;

      }

      _synchronous_lock slGraphics(m_puserinteractionimpl->m_pgraphicsgraphics->synchronization());

      auto pitem = m_puserinteractionimpl->m_pgraphicsgraphics->get_screen_item();

      _synchronous_lock slImage(pitem->m_pmutex);


      //pitem->m_pimage2;

      if(pitem && pitem->m_pimage2 && pitem->m_pimage2.ok())
      {
         // cairo_set_source_rgba(cr, 0, 0, 0, 0); // Fully transparent background
         // cairo_set_operator(cr, CAIRO_OPERATOR_CLEAR);
         // cairo_paint(cr);
         //
         // cairo_set_source_rgba(cr, 0, 0, 0, 0.5); // Fully transparent background
         // cairo_set_operator(cr, CAIRO_OPERATOR_SOURCE);
         // cairo_paint(cr);
         //
         // cairo_set_source_rgba(cr, 0.1, 0.5, 0.8, 0.7);
         // //
         // // // Draw rectangle
         // cairo_rectangle(cr, 50, 50, 200, 100); // x, y, width, height
         // cairo_fill(cr);
         //
         // return;

         auto pgraphics = __create<::draw2d::graphics>();

         pgraphics->attach(cr);
         //pgraphics->set_alpha_mode(::draw2d::e_alpha_mode_set);
         ::rectangle_f64 r;
         int width = gtk_widget_get_width(widget);
         int height = gtk_widget_get_height(widget);
         r.left() = 0;
         r.top() = 0;
         r.right() = width;
         r.bottom() = height;
         //r.set_size(m_sizeOnSize);
         ///pgraphics->fill_solid_rectangle(r, argb(0, 0, 0, 0));
         pgraphics->set_alpha_mode(::draw2d::e_alpha_mode_set);
         ::image::image_source imagesource(pitem->m_pimage2, r);
         ::image::image_drawing_options imagedrawingoptions(r);
         ::image::image_drawing imagedrawing(imagedrawingoptions, imagesource);
         pgraphics->draw(imagedrawing);
         //pgraphics->set_text_color(::color::white);
         //::string strSize;
         //strSize.formatf("Size: %d, %d\nSizeOnSize: %d, %d", width, height, m_sizeOnSize.cx(), m_sizeOnSize.cy());
         //pgraphics->text_out({10, 10}, strSize);
         pgraphics->detach();
         m_puserinteractionimpl->m_pgraphicsgraphics->on_end_draw();
      }


      // ::rectangle_f64 r;
      //
      // r.left() = 10;
      // r.top() = 10;
      // r.right() = 80;
      // r.bottom() = 80;
      //
      // pgraphics->fill_solid_rectangle(r, argb(1.0,0.1, 0.5, 0.8 ));


      // cairo_set_source_rgba(cr, 0, 0, 0, 0); // Fully transparent background
      // cairo_set_operator(cr, CAIRO_OPERATOR_SOURCE);
      // cairo_paint(cr);
      // // Set color for drawing (RGB)
      // cairo_set_source_rgb(cr, 0.1, 0.5, 0.8);
      //
      // // Draw rectangle
      // cairo_rectangle(cr, 50, 50, 200, 100); // x, y, width, height
      // cairo_fill(cr);
      //
      // // Set color for ellipse
      // cairo_set_source_rgb(cr, 0.8, 0.1, 0.5);
      //
      // // Draw ellipse
      // cairo_save(cr);
      // cairo_translate(cr, 150, 250); // Move to center of the ellipse
      // cairo_scale(cr, 1.5, 1.0);     // Scale to make an ellipse
      // cairo_arc(cr, 0, 0, 50, 0, 2 * G_PI); // Draw a circle, but scaled
      // cairo_restore(cr);
      //
      // cairo_fill(cr);

      //return FALSE;
   }

   // Callback function to handle window resize events
   static void on_size_allocate(GtkWidget* widget, GdkRectangle* allocation, gpointer p)
   {
      // Print the new size of the window
      auto pwindow = (::windowing_gtk4::window *)p;
      pwindow->_on_size(allocation->width, allocation->height);
      //g_print("Window resized: width=%d, height=%d\n", allocation->width, allocation->height);
      //return false;
   }


//    static void on_window_configure_event(GdkWindow *window, GdkEventConfigure *event, gpointer user_data) {
//       // Handle window resize event here
// //      g_print("Window resized to %dx%d\n", event->width, event->height);
//       auto pwindow = (::windowing_gtk4::window *)p;
//       pwindow->_on_size(allocation->width, allocation->height);
//    }
//

   // gboolean on_window_property_notify_event (GtkWidget* self, GdkEventProperty event, gpointer user_data)
   // {
   //
   // }



   //
   // static void on_activate(GtkApplication *app, gpointer user_data)
   // {
   //
   //    GtkWidget *window = gtk_application_window_new(app);
   //
   //    gtk_window_set_title(GTK_WINDOW(window), "Window State Example");
   //
   //    gtk_window_set_default_size(GTK_WINDOW(window), 400, 300);
   //
   //    gtk_window_present(GTK_WINDOW(window));
   //
   // }


   // int main(int argc, char **argv)
   // {
   //
   //    GtkApplication *app;
   //
   //    int status;
   //
   //    app = gtk_application_new("com.example.WindowState", G_APPLICATION_FLAGS_NONE);
   //
   //    g_signal_connect(app, "activate", G_CALLBACK(on_activate), NULL);
   //
   //    status = g_application_run(G_APPLICATION(app), argc, argv);
   //
   //    g_object_unref(app);
   //
   //    return status;
   //
   // }




   void window::_on_display_change(::e_display edisplay)
   {

      main_post([this, edisplay]()
                {
// auto cxAllocated = gtk_widget_get_allocated_width(m_pgtkwidget);
// auto cyAllocated = gtk_widget_get_allocated_height(m_pgtkwidget);

GdkSurface *pgdksurface = gtk_native_get_surface(GTK_NATIVE(m_pgtkwidget));
// GdkToplevel *toplevel = GDK_TOPLEVEL(surface);

if (edisplay == e_display_zoomed)
{

// auto pgdktoplevellayout = gdk_toplevel_layout_new();
//
// gdk_toplevel_layout_set_maximized(pgdktoplevellayout, true);
//
//
// GdkToplevel * pgdktoplevel = GDK_TOPLEVEL(pgdksurface);
//
// gdk_toplevel_present(pgdktoplevel, pgdktoplevellayout);

m_puserinteractionimpl->m_puserinteraction->display(::e_display_zoomed);

application()->fork(
[this]()
{
  preempt(100_ms);

  user_post(
     [this]()
     {
        GdkSurface *pgdksurface = gtk_native_get_surface(GTK_NATIVE(m_pgtkwidget));

        int cx = gdk_surface_get_width(pgdksurface);

        int cy = gdk_surface_get_height(pgdksurface);

        _on_size(cx, cy);
     });
});
}
else
{

m_puserinteractionimpl->m_puserinteraction->display(::e_display_normal);

application()->fork(
[this]()
{
  preempt(100_ms);

  user_post(
     [this]()
     {
        GdkSurface *pgdksurface = gtk_native_get_surface(GTK_NATIVE(m_pgtkwidget));

        int cx = gdk_surface_get_width(pgdksurface);

        int cy = gdk_surface_get_height(pgdksurface);

        _on_size(cx, cy);
     });
});
}


// gdk_surface_request_layout(pgdksurface);

// gdk_toplevel_size_get_bounds()

});

   }


   void window::_on_size(int cx, int cy)
   {
      ::user::interaction_impl* pimpl = m_puserinteractionimpl;


      auto puserinteraction = pimpl->m_puserinteraction;

      ::size_i32 s(cx, cy);


      if(m_sizeOnSize != s)
      {

         //gtk_drawing_area_set_content_width (GTK_DRAWING_AREA (m_pdrawingarea), cx);
         //gtk_drawing_area_set_content_height (GTK_DRAWING_AREA (m_pdrawingarea), cy);

         m_sizeOnSize = s;

         puserinteraction->set_size(s);

         puserinteraction->set_need_layout();

         puserinteraction->set_need_redraw();

         puserinteraction->post_redraw();

      }


   }


   // // Define custom regions for resizing
   // enum
   // {
   //    RESIZE_NONE = 0,
   //    RESIZE_TOP = 1 << 0,
   //    RESIZE_BOTTOM = 1 << 1,
   //    RESIZE_LEFT = 1 << 2,
   //    RESIZE_RIGHT = 1 << 3
   // };

   // // Detect which edge is being resized
   // static enum_window_edge detect_resize_edge(GtkWidget* window, int x, int y)
   // {
   //    enum_window_edge edge = e_window_edge_none;
   //
   //    int width = gtk_widget_get_width(window);
   //    int height = gtk_widget_get_height(window);
   //
   //    // Allow resizing near the window borders (e.g., 10px near the edges)
   //    int border = 10;
   //
   //    if (x < border)
   //    {
   //       if (y < border)
   //       {
   //          edge = e_window_edge_north_west;
   //       }
   //       else if (y > height - border)
   //       {
   //          edge = e_window_edge_south_west;
   //       }
   //       else
   //       {
   //          edge = e_window_edge_west;
   //       }
   //    }
   //    else if (x > width - border)
   //    {
   //       if (y < border)
   //       {
   //          edge = e_window_edge_north_east;
   //       }
   //       else if (y > height - border)
   //       {
   //          edge = e_window_edge_south_east;
   //       }
   //       else
   //       {
   //          edge = e_window_edge_east;
   //       }
   //    }
   //    else if (y < border)
   //    {
   //       edge = e_window_edge_north;
   //    }
   //    else if(y > height - border)
   //    {
   //       edge = e_window_edge_south;
   //    }
   //
   //    return edge;
   //
   // }


   void window::_on_window_button_pressed(::operating_system::a_system_menu_item * pitem, GtkGestureClick * pgesture, int n_press, double x, double y)
   {

      ::gtk4::nano::user::window::_on_window_button_pressed(pitem, pgesture, n_press, x, y);
      // if(n_press == 1)
      // {
      //    guint button = gtk_gesture_single_get_current_button(GTK_GESTURE_SINGLE(pgesture));
      //
      //    GdkEventSequence *sequence = gtk_gesture_get_last_updated_sequence(GTK_GESTURE(pgesture));
      //
      //    // Get the GdkEvent from the sequence
      //    GdkEvent *event = gtk_gesture_get_last_event(GTK_GESTURE(pgesture), sequence);
      //
      //    guint32 timestamp = gdk_event_get_time (event);
      //
      //    auto pmouse = __create_new<::message::mouse>();
      //
      //    pmouse->m_oswindow = this;
      //
      //    pmouse->m_pwindow = this;
      //
      //    pmouse->m_iTimestamp = timestamp;
      //
      //    if (button == 1)
      //    {
      //       pmouse->m_atom = e_message_left_button_down;
      //    }
      //    else if (button == 3)
      //    {
      //       pmouse->m_atom = e_message_right_button_down;
      //    }
      //    else if (button == 2)
      //    {
      //       pmouse->m_atom = e_message_middle_button_down;
      //    }
      //
      //
      //    if(pitem->m_strAtom == "***move")
      //    {
      //
      //       gtk_gesture_set_state (GTK_GESTURE (pgesture), GTK_EVENT_SEQUENCE_CLAIMED);
      //
      //       GdkEventSequence *sequence = gtk_gesture_get_last_updated_sequence(GTK_GESTURE(pgesture));
      //
      //       // Get the GdkEvent from the sequence
      //       GdkEvent *event = gtk_gesture_get_last_event(GTK_GESTURE(pgesture), sequence);
      //
      //       guint32 timestamp = gdk_event_get_time (event);
      //
      //       auto pgdkdisplay = gtk4_display()->m_pgdkdisplay;
      //
      //       GdkSeat * pgdkseat = gdk_display_get_default_seat(pgdkdisplay);
      //
      //       // Get the default pointer device (e.g., mouse)
      //       GdkDevice *pgdkdevicePointer = gdk_seat_get_pointer(pgdkseat);
      //
      //       m_pointCursor2.x() = m_sizeOnSize.cx()/2;
      //       m_pointCursor2.y() = m_sizeOnSize.cy()/2;
      //
      //
      //       pmouse->m_pointHost = m_pointCursor2;
      //
      //       pmouse->m_pointAbsolute = m_pointCursor2;
      //
      //
      //
      //
      //
      //       //auto ppopover = GTK_POPOVER(gtk_widget_get_ancestor(pwidget, GTK_TYPE_POPOVER_MENU));
      //
      //       //gtk_widget_set_visible(GTK_WIDGET(ppopover), false);
      //       auto * pwidget = (GtkWidget *) pitem->m_pWidgetImpl;
      //       auto ppopover = GTK_POPOVER(gtk_widget_get_ancestor(pwidget, GTK_TYPE_POPOVER_MENU));
      //
      //       gtk_widget_set_visible(GTK_WIDGET(ppopover), false);
      //
      //
      //       //defer_perform_entire_reposition_process(pmouse);
      //       gtk_popover_popdown(ppopover);
      //
      //       preempt(100_ms);
      //
      //
      //       GdkSurface *surface = gtk_native_get_surface(gtk_widget_get_native(m_pgtkwidget));
      //       gdk_toplevel_begin_move(
      //          GDK_TOPLEVEL(surface),
      //          pgdkdevicePointer,
      //          gtk_gesture_single_get_current_button(GTK_GESTURE_SINGLE(pgesture)),
      //          m_pointCursor2.x(),
      //          m_pointCursor2.y(), timestamp);
      //
      //       gtk_event_controller_reset (GTK_EVENT_CONTROLLER (pgesture));
      //
      //
      //
      //       // //m_bPendingStartMove = true;
      //       // int a = m_sizeOnSize.cx()/2;
      //       // int b = m_sizeOnSize.cy()/2;
      //       //
      //       // // Simulate a "pressed" signal on GtkGestureClick
      //       // g_signal_emit_by_name(m_pgtkgestureClick, "pressed", 1, a, b);  // Simulating a left-click at position (100, 100)
      //
      //
      //       //defer_perform_entire_reposition_process(pmouse);
      //       //gtk_popover_popdown(ppopover);
      //
      //
      //    }
      //    else if(pitem->m_strAtom ==  "***size")
      //    {
      //       // m_pointCursor2.x() = 4;
      //       // m_pointCursor2.y() = 4;
      //       //
      //       //
      //       // pmouse->m_pointHost = m_pointCursor2;
      //       //
      //       // pmouse->m_pointAbsolute = m_pointCursor2;
      //       // //
      //       // // defer_perform_entire_resizing_process(::experience::e_frame_sizing_top_left, pmouse);
      //       //
      //       // auto ppopover = GTK_POPOVER(gtk_widget_get_ancestor(pwidget, GTK_TYPE_POPOVER_MENU));
      //       //
      //       // gtk_widget_set_visible(GTK_WIDGET(ppopover), false);
      //       //
      //       //
      //       // //defer_perform_entire_reposition_process(pmouse);
      //       // gtk_popover_popdown(ppopover);
      //
      //
      //       gtk_gesture_set_state (GTK_GESTURE (pgesture), GTK_EVENT_SEQUENCE_CLAIMED);
      //
      //       GdkEventSequence *sequence = gtk_gesture_get_last_updated_sequence(GTK_GESTURE(pgesture));
      //
      //       // Get the GdkEvent from the sequence
      //       GdkEvent *event = gtk_gesture_get_last_event(GTK_GESTURE(pgesture), sequence);
      //
      //       guint32 timestamp = gdk_event_get_time (event);
      //
      //       auto pgdkdisplay = gtk4_display()->m_pgdkdisplay;
      //
      //       GdkSeat * pgdkseat = gdk_display_get_default_seat(pgdkdisplay);
      //
      //       // Get the default pointer device (e.g., mouse)
      //       GdkDevice *pgdkdevicePointer = gdk_seat_get_pointer(pgdkseat);
      //
      //       m_pointCursor2.x() = m_sizeOnSize.cx()/2;
      //       m_pointCursor2.y() = m_sizeOnSize.cy()/2;
      //
      //
      //       pmouse->m_pointHost = m_pointCursor2;
      //
      //       pmouse->m_pointAbsolute = m_pointCursor2;
      //
      //
      //
      //
      //
      //       //auto ppopover = GTK_POPOVER(gtk_widget_get_ancestor(pwidget, GTK_TYPE_POPOVER_MENU));
      //
      //       //gtk_widget_set_visible(GTK_WIDGET(ppopover), false);
      //       auto * pwidget = (GtkWidget *) pitem->m_pWidgetImpl;
      //       auto ppopover = GTK_POPOVER(gtk_widget_get_ancestor(pwidget, GTK_TYPE_POPOVER_MENU));
      //
      //       gtk_widget_set_visible(GTK_WIDGET(ppopover), false);
      //
      //
      //       //defer_perform_entire_reposition_process(pmouse);
      //       gtk_popover_popdown(ppopover);
      //
      //       preempt(100_ms);
      //
      //
      //       GdkSurface *surface = gtk_native_get_surface(gtk_widget_get_native(m_pgtkwidget));
      //       gdk_toplevel_begin_resize(
      //          GDK_TOPLEVEL(surface),
      //          GDK_SURFACE_EDGE_NORTH_WEST,
      //          pgdkdevicePointer,
      //          gtk_gesture_single_get_current_button(GTK_GESTURE_SINGLE(pgesture)),
      //          m_pointCursor2.x(),
      //          m_pointCursor2.y(), timestamp);
      //
      //       gtk_event_controller_reset (GTK_EVENT_CONTROLLER (pgesture));
      //
      //
      //    }
      //
      // }

   }



   void window::_on_window_button_released(::operating_system::a_system_menu_item * pitem, GtkGestureClick * pgesture, int n_press, double x, double y)
   {

      ::gtk4::nano::user::window::_on_window_button_released(pitem, pgesture, n_press, x, y);

      // if(n_press == 1)
      // {
      //    guint button = gtk_gesture_single_get_current_button(GTK_GESTURE_SINGLE(pgesture));
      //
      //    GdkEventSequence *sequence = gtk_gesture_get_last_updated_sequence(GTK_GESTURE(pgesture));
      //
      //    // Get the GdkEvent from the sequence
      //    GdkEvent *event = gtk_gesture_get_last_event(GTK_GESTURE(pgesture), sequence);
      //
      //    guint32 timestamp = gdk_event_get_time (event);
      //
      //    auto pmouse = __create_new<::message::mouse>();
      //
      //    pmouse->m_oswindow = this;
      //
      //    pmouse->m_pwindow = this;
      //
      //    pmouse->m_iTimestamp = timestamp;
      //
      //    if (button == 1)
      //    {
      //       pmouse->m_atom = e_message_left_button_down;
      //    }
      //    else if (button == 3)
      //    {
      //       pmouse->m_atom = e_message_right_button_down;
      //    }
      //    else if (button == 2)
      //    {
      //       pmouse->m_atom = e_message_middle_button_down;
      //    }
      //
      //
      //    if(pitem->m_strAtom == "***move")
      //    {
      //
      //
      //       m_pointCursor2.x() = m_sizeOnSize.cx()/2;
      //       m_pointCursor2.y() = m_sizeOnSize.cy()/2;
      //
      //
      //       pmouse->m_pointHost = m_pointCursor2;
      //
      //       pmouse->m_pointAbsolute = m_pointCursor2;
      //
      //
      //
      //       //
      //       // //auto ppopover = GTK_POPOVER(gtk_widget_get_ancestor(pwidget, GTK_TYPE_POPOVER_MENU));
      //       //
      //       // //gtk_widget_set_visible(GTK_WIDGET(ppopover), false);
      //       // auto ppopover = GTK_POPOVER(gtk_widget_get_ancestor(pwidget, GTK_TYPE_POPOVER_MENU));
      //       //
      //       // gtk_widget_set_visible(GTK_WIDGET(ppopover), false);
      //       //
      //       //
      //       // //defer_perform_entire_reposition_process(pmouse);
      //       // gtk_popover_popdown(ppopover);
      //       //
      //       // m_bPendingStartMove = true;
      //       // //defer_perform_entire_reposition_process(pmouse);
      //       // //gtk_popover_popdown(ppopover);
      //
      //
      //    }
      //    else if(pitem->m_strAtom == "***size")
      //    {
      //       m_pointCursor2.x() = 4;
      //       m_pointCursor2.y() = 4;
      //
      //
      //       pmouse->m_pointHost = m_pointCursor2;
      //
      //       pmouse->m_pointAbsolute = m_pointCursor2;
      //
      //       defer_perform_entire_resizing_process(::experience::e_frame_sizing_top_left, pmouse);
      //    }
      //
      // }

   }


   void window::on_initialize_particle()
   {

      ::windowing_posix::window::on_initialize_particle();
      ::gtk4::nano::user::window::on_initialize_particle();

   }


   void window::_on_button_pressed(GtkGestureClick* pgesture, int n_press, double x, double y)
   {
      if(n_press == 1)
      {
         guint button = gtk_gesture_single_get_current_button(GTK_GESTURE_SINGLE(pgesture));
         // //GtkWidget* window = gtk_event_controller_get_widget(GTK_EVENT_CONTROLLER(pgesture));
         //
         // resize_edge = detect_resize_edge(m_pgtkwidget, x, y);
         //
         // if (button == 1)
         // {
         //    if (resize_edge != e_window_edge_none)
         //    {
         //
         //       if(gtk4_windowing()->m_pnanouserdisplay->is_x11())
         //       {
         //          // Start resizing
         //          resizing = TRUE;
         //          start_x = x;
         //          start_y = y;
         //          auto r = _unlocked_defer_get_window_rectangle();
         //          start_window_x = r.left();
         //          start_window_y = r.right();
         //          start_width = r.width();
         //          start_height = r.height();
         //
         //       }
         //       else
         //       {
         //          return;
         //
         //       }
         //    }
         //    else
         //    {
         //       if(gtk4_windowing()->m_pnanouserdisplay->is_x11())
         //       {
         //          // Start moving
         //          moving = TRUE;
         //          start_x = x;
         //          start_y = y;
         //          auto r = _unlocked_defer_get_window_rectangle();
         //          start_window_x = r.left();
         //          start_window_y = r.right();
         //          start_width = r.width();
         //          start_height = r.height();
         //
         //       }
         //    }
         // }
         auto puserinteractionimpl = m_puserinteractionimpl;

         if (::is_set(puserinteractionimpl))
         {
            auto pmouse = __create_new<::message::mouse>();

            pmouse->m_oswindow = this;

            pmouse->m_pwindow = this;

            GdkEventSequence *sequence = gtk_gesture_get_last_updated_sequence(GTK_GESTURE(pgesture));

            // Get the GdkEvent from the sequence
            GdkEvent *event = gtk_gesture_get_last_event(GTK_GESTURE(pgesture), sequence);

            guint32 timestamp = gdk_event_get_time (event);

            pmouse->m_iTimestamp = timestamp;

            if (button == 1)
            {
               pmouse->m_atom = e_message_left_button_down;
            }
            else if (button == 3)
            {
               pmouse->m_atom = e_message_right_button_down;
            }
            else if (button == 2)
            {
               pmouse->m_atom = e_message_middle_button_down;
            }

            m_pointCursor2.x() = x;
            m_pointCursor2.y() = y;


            pmouse->m_pointHost = m_pointCursor2;

            pmouse->m_pointAbsolute = m_pointCursor2;

            //pmouse->m_time.m_iSecond = millis / 1_k;

            //pmouse->m_time.m_iNanosecond = (millis % 1_k) * 1_M;

            //pwindow->message_handler(pmouse);

            //wayland_windowing()->post_ui_message(pmouse);

            if(m_bPendingStartMove)
            {
               m_bPendingStartMove =false;

               defer_perform_entire_reposition_process(pmouse);
               return;

            }

            puserinteractionimpl->message_handler(pmouse);
         }

      }

   }




   void window::_on_button_released(GtkGestureClick* pgesture, int n_press, double x, double y)
   {

      if(n_press == 1)
      {

         auto button = gtk_gesture_single_get_current_button(GTK_GESTURE_SINGLE(pgesture));

         if (button == 1)
         {

            moving = FALSE;
            resizing = FALSE;
         }


         auto puserinteractionimpl = m_puserinteractionimpl;

         if (::is_set(puserinteractionimpl))
         {
            
            auto pmouse = __create_new<::message::mouse>();

            pmouse->m_oswindow = this;

            pmouse->m_pwindow = this;

            if (button == 1)
            {
               pmouse->m_atom = e_message_left_button_up;
            }
            else if (button == 3)
            {
               pmouse->m_atom = e_message_right_button_up;
            }
            else if (button == 2)
            {
               pmouse->m_atom = e_message_middle_button_up;
            }

            m_pointCursor2.x() = x;
            m_pointCursor2.y() = y;


            pmouse->m_pointHost = m_pointCursor2;

            pmouse->m_pointAbsolute = m_pointCursor2;

            //pmouse->m_time.m_iSecond = millis / 1_k;

            //pmouse->m_time.m_iNanosecond = (millis % 1_k) * 1_M;

            //pwindow->message_handler(pmouse);

            //wayland_windowing()->post_ui_message(pmouse);

            puserinteractionimpl->message_handler(pmouse);
         }


      }
   }




   void window::_on_motion_notify(GtkEventControllerMotion* pcontroller, double x, double y)
   {


      //  if (resizing)
      // {
      //
      //     if(gtk4_windowing()->m_pnanouserdisplay->is_x11())
      //     {
      //        auto cursor_name = _gtk_get_resize_cursor_name(resize_edge);
      //        // Resize the window
      //        int dx = x - start_x;
      //        int dy = y - start_y;
      //        int new_width = start_width;
      //        int new_height = start_height;
      //        int xset = INT_MIN;
      //        int yset = INT_MIN;
      //
      //        if (resize_edge == e_window_edge_east || resize_edge == e_window_edge_north_east  || resize_edge == e_window_edge_south_east)
      //           new_width += dx;
      //        if (resize_edge == e_window_edge_west || resize_edge == e_window_edge_north_west  || resize_edge == e_window_edge_south_west)
      //        {
      //           new_width -= dx;
      //           xset=start_window_x + dx;
      //           yset=start_window_y;
      //        }
      //        if (resize_edge == e_window_edge_south || resize_edge == e_window_edge_south_east  || resize_edge == e_window_edge_south_west)
      //           new_height += dy;
      //        if  (resize_edge == e_window_edge_north || resize_edge == e_window_edge_north_east  || resize_edge == e_window_edge_north_west)
      //        {
      //           new_height -= dy;
      //           xset=start_window_x;
      //           yset=start_window_y + dy;
      //        }
      //
      //        new_width = MAX(new_width, 100); // Set minimum size
      //        new_height = MAX(new_height, 100);
      //
      //        if(xset != INT_MIN && yset != INT_MIN)
      //        {
      //
      //           _unlocked_defer_set_window_position({xset, yset}, {new_width, new_height});
      //
      //        }
      //        else
      //        {
      //           _unlocked_defer_set_window_size({new_width, new_height});
      //        }
      //     }
      // }
      // else if (moving)
      // {
      //    if(gtk4_windowing()->m_pnanouserdisplay->is_x11())
      //    {
      //       // Move the window
      //       int dx = x - start_x;
      //       int dy = y - start_y;
      //       _unlocked_defer_set_window_position({start_window_x + dx, start_window_y + dy});
      //    }
      // }
      // else
      // {
      //
      //    auto edge = detect_resize_edge(m_pgtkwidget, x, y);
      //
      //    //GdkWindow* gdk_window = gtk_widget_get_window(widget);
      //    //      GdkDisplay* display = gdk_window_get_display(gdk_window);
      //
      //    auto cursor_name = _gtk_get_resize_cursor_name(edge);
      //
      //    _set_cursor_from_name(cursor_name);
      //
      // }

      auto puserinteractionimpl = m_puserinteractionimpl;

      if(::is_set(puserinteractionimpl))
      {

         auto pmouse = __create_new<::message::mouse>();

         pmouse->m_oswindow = this;

         pmouse->m_pwindow = this;

         pmouse->m_atom = e_message_mouse_move;


         //pmouse->m_time.m_iSecond = millis / 1_k;

         //pmouse->m_time.m_iNanosecond = (millis % 1_k) * 1_M;

         //pwindow->message_handler(pmouse);

         //wayland_windowing()->post_ui_message(pmouse);

         if(m_bPendingStartMove)
         {

            m_bPendingStartMove = false;


            gtk_gesture_set_state (GTK_GESTURE (pcontroller), GTK_EVENT_SEQUENCE_CLAIMED);


            m_pointCursor2.x() = m_sizeOnSize.cx()/2;
            m_pointCursor2.y() = m_sizeOnSize.cy()/2;

            GdkEvent *event = gtk_event_controller_get_current_event(GTK_EVENT_CONTROLLER(pcontroller));
            guint32 timestamp = gdk_event_get_time(event);

            g_print("Motion event at x=%.2f, y=%.2f with timestamp: %u\n", x, y, timestamp);

            // if (event) {
            //    gdk_event_unref(event);  // Free the event object after use
            // }

            auto pmouse = __create_new<::message::mouse>();

            pmouse->m_iTimestamp = timestamp;

         guint button = 0;

         //auto pgdkeventsequence = gdk_event_get_event_sequence(event);

         auto toplevel = gtk_native_get_surface(GTK_NATIVE(m_pgtkwidget));


         auto pgdkdisplay = gtk4_display()->m_pgdkdisplay;

         GdkSeat * pgdkseat = gdk_display_get_default_seat(pgdkdisplay);

         // Get the default pointer device (e.g., mouse)
         GdkDevice *pgdkdevicePointer = gdk_seat_get_pointer(pgdkseat);
         double x;
         double y;
            x = gtk_widget_get_width(m_pgtkwidget);
            y = gtk_widget_get_height(m_pgtkwidget);

            x/=2;
            y/=2;

            //x = 0;
            //y = 0;

            auto pgdkdevice = gdk_event_get_device (event);

         //gdk_toplevel_begin_move(GDK_TOPLEVEL(toplevel), pgdkdevicePointer, button, x, y, timestamp);

            gdk_toplevel_begin_move(GDK_TOPLEVEL(toplevel), pgdkdevice, button, x, y, timestamp);

            gtk_event_controller_reset (GTK_EVENT_CONTROLLER (pcontroller));
            return;

         }

         m_pointCursor2.x() = x;
         m_pointCursor2.y() = y;


         pmouse->m_pointHost = m_pointCursor2;

         pmouse->m_pointAbsolute = m_pointCursor2;


         puserinteractionimpl->message_handler(pmouse);

      }

   }



   void window::_on_enter_notify(GtkEventControllerMotion* pcontroller, double x, double y)
   {

//      GtkWidget* widget = gtk_event_controller_get_widget(GTK_EVENT_CONTROLLER(pcontroller));


   }


   void window::_on_window_visibility_changed(GObject* object, GParamSpec* pspec)
   {
      GtkWindow* window = GTK_WINDOW(object);
      gboolean is_visible = gtk_widget_get_visible(GTK_WIDGET(window));

      if (!is_visible)
      {
         //      g_print("Window has been minimized (hidden).\n");
      }
      else
      {
         g_print("Window has been restored.\n");

         ::user::interaction_impl* pimpl = m_puserinteractionimpl;

         pimpl->m_puserinteraction->display(::e_display_normal);

         pimpl->m_puserinteraction->set_need_layout();

         pimpl->m_puserinteraction->set_need_redraw();

         pimpl->m_puserinteraction->post_redraw();
      }
   }


   //
   // void window::_on_window_simple_action(const char * pszActionName)
   // {
   //
   //    ::string strActionName(pszActionName);
   //
   //    if(strActionName == "minimize")
   //    {
   //
   //       window_minimize();
   //
   //    }
   //    else if(strActionName == "maximize")
   //    {
   //
   //       window_maximize();
   //
   //    }
   //    else if(strActionName == "maximize")
   //    {
   //
   //       window_maximize();
   //
   //    }
   //    else if(strActionName == "about_box")
   //    {
   //
   //       application()->show_about_box();
   //
   //    }
   //    else if(strActionName == "close")
   //    {
   //
   //       m_puserinteractionimpl->m_puserinteraction->post_message(e_message_close);
   //
   //    }
   //    else if(strActionName == "")
   //    {
   //
   //       print_line("reaching here?!");
   //       //defer_perform_entire_reposition_process(nullptr);
   //
   //    }
   //    else if(strActionName == "")
   //    {
   //
   //       print_line("also here");
   //
   //       //defer_perform_entire_resizing_process(::experience::e_frame_sizing_top_left, nullptr);
   //
   //    }
   //
   // }
   //


   void window::_on_toplevel_compute_size(GdkToplevel * self, GdkToplevelSize* size)
   {

      gboolean bIsMaximized = gtk_window_is_maximized(GTK_WINDOW(m_pgtkwidget));

      if(bIsMaximized)
      {

         int w = 0;

         int h = 0;

         gdk_toplevel_size_get_bounds(size, &w, &h);

         gdk_toplevel_size_set_size(size, w, h);

      }

   }


   //void window::create_window(::user::interaction_impl * pimpl)
   void window::create_window()
   {

      bool bOk = false;

      user_send([this, &bOk]()
      {

         ::user::interaction_impl* pimpl = m_puserinteractionimpl;

         _synchronous_lock synchronouslock(user_synchronization());

         auto pusersystem = pimpl->m_puserinteraction->m_pusersystem;

         pimpl->m_puserinteraction->m_bMessageWindow = false;

         auto pgtk4windowing = gtk4_windowing();

         auto pdisplay = pgtk4windowing->m_pdisplay;


         m_puserinteractionimpl = pimpl;

         m_puserinteractionimpl->m_puserinteraction->m_pwindow = this;


         m_puserinteractionimpl->m_puserinteraction->m_puserinteractionTopLevel = m_puserinteractionimpl->
            m_puserinteraction;

         m_pdisplaybase = pdisplay;

         m_pgtk4display = m_pdisplaybase;

         m_puserinteractionbase = m_puserinteractionimpl->m_puserinteraction;

         //m_pnanouserdisplaybase = pdisplay;

         information() << "window::create_window m_pnanouserdisplay : " << (::iptr)m_pdisplaybase.m_p;

         //information() << "window::create_window m_pnanouserdisplaybase : " << (::iptr) m_pnanouserdisplaybase.m_p;

         pimpl->m_pwindow = this;

         // printf("pimpl->m_pwindow.m_p (0x%x)\n", pimpl->m_pwindow.m_p);
         // printf("pimpl->m_pwindow.m_pelement (0x%x)\n", pimpl->m_pwindow.m_pelement);

         //display_lock displaylock(pdisplayx11->Display());

         int x = m_puserinteractionimpl->m_puserinteraction->const_layout().sketch().origin().x();

         int y = m_puserinteractionimpl->m_puserinteraction->const_layout().sketch().origin().y();

         int cx = m_puserinteractionimpl->m_puserinteraction->const_layout().sketch().width();

         int cy = m_puserinteractionimpl->m_puserinteraction->const_layout().sketch().height();

         bool bVisible = m_puserinteractionimpl->m_puserinteraction->const_layout().sketch().is_screen_visible();


         if (cx <= 0)
         {
            cx = 1;
         }

         if (cy <= 0)
         {
            cy = 1;
         }


         {
            m_pointWindow.x() = 0;

            m_pointWindow.y() = 0;
         }

         //m_pointWindowBestEffort.x() = x;

         //m_pointWindowBestEffort.y() = y;

         m_sizeWindow.cx() = cx;

         m_sizeWindow.cy() = cy;

         _create_window();



         set_oswindow(this);


         pimpl->m_puserinteraction->m_pinteractionimpl = pimpl;

         pimpl->m_puserinteraction->increment_reference_count(
            REFERENCING_DEBUGGING_P_NOTE(this, "native_create_window"));


         m_puserinteractionimpl->m_puserinteraction->__defer_set_owner_to_impl();

         bamf_set_icon();

         if (bVisible)
         {

            map_window();

         }
         else
         {

            pimpl->m_puserinteraction->const_layout().window().display() = e_display_none;

         }

         bOk = true;

      });

      if (bOk)
      {

         ::user::interaction_impl* pimpl = m_puserinteractionimpl;

   #ifdef REPORT_OFFSET

            printf("(7BB) offset of m_timeFocusStart in ::user::prototype = %d\n", offsetof(::user::prototype,m_timeFocusStart));
            printf("(7BB) offset of m_bExtendOnParent in ::user::interaction = %d\n", offsetof(::user::interaction, m_bExtendOnParent));
            printf("(7BB) offset of m_pwindow in ::user::interaction = %d\n", offsetof(::user::interaction, m_pwindow));
            printf("(7BB) offset of m_pImpl2 in ::user::interaction_impl = %d\n", offsetof(::user::interaction_impl, m_pImpl2));
            printf("(7BB) offset of m_timeLastExposureAddUp in ::user::interaction_impl = %d\n", offsetof(::user::interaction_impl, m_timeLastExposureAddUp));
            printf("(7BB) offset of m_strBitmapSource in ::user::interaction_impl = %d\n", offsetof(::user::interaction_impl, m_strBitmapSource));
            printf("(7BB) offset of m_bCursorRedraw in ::user::interaction_impl = %d\n", offsetof(::user::interaction_impl, m_bCursorRedraw));
            printf("(7BB) offset of m_bLockWindowUpdate in ::user::interaction_impl = %d\n", offsetof(::user::interaction_impl, m_bLockWindowUpdate));
            printf("(7BB) offset of m_bOkToUpdateScreen in ::user::interaction_impl = %d\n", offsetof(::user::interaction_impl, m_bOkToUpdateScreen));
            printf("(7BB) offset of m_sizeDrawn in ::user::interaction_impl = %d\n", offsetof(::user::interaction_impl, m_sizeDrawn));
            printf("(7BB) offset of m_pthreadMouseLeave in ::user::interaction_impl = %d\n", offsetof(::user::interaction_impl, m_pthreadMouseLeave));
            printf("(7BB) offset of m_bPointInside in ::user::interaction_impl = %d\n", offsetof(::user::interaction_impl, m_bPointInside));
            printf("(7BB) offset of m_pwindow in ::user::interaction_impl = %d\n", offsetof(::user::interaction_impl, m_pwindow));

   #endif

         auto lresult = pimpl->m_puserinteraction->send_message(e_message_create, 0, 0);

         if (lresult == -1)
         {
            throw ::exception(error_failed);
         }

         pimpl->m_puserinteraction->m_ewindowflag |= e_window_flag_window_created;

         pimpl->m_puserinteraction->set_flag(e_flag_task_started);

         //auto lresult2 = pimpl->m_puserinteraction->send_message(e_message_pos_create, 0, 0);
      }

      if (!bOk)
      {
         throw ::exception(error_failed);
      }
   }


void window::destroy()
{
   ::windowing_posix::window::destroy();

   //::wayland::nano::user::window_base::destroy();
}

//   void window::__map()
//   {
//
//      if (m_pxdgtoplevel != nullptr || m_pxdgpopup != nullptr)
//      {
//
//         return;
//
//      }
//
//      information() << "windowing_gtk4::window::__map";
//
//      ::minimum(m_sizeConfigure.cx());
//
//      ::minimum(m_sizeConfigure.cy());
//
//      m_bDoneFirstMapping = false;
//
//      //m_bXdgInitialConfigure = false;
//
//      m_uLastRequestSerial = 0;
//
//      m_uLastConfigureSerial = 0;
//
//      m_uLastAckSerial = 0;
//
//      auto pdisplaywayaland = dynamic_cast < ::windowing_gtk4::display * > (m_pnanouserdisplay.m_p);
//
//      m_pwlsurface = wl_compositor_create_surface(pdisplaywayaland->m_pwlcompositor);
//
//      if (m_pwlsurface == NULL)
//      {
//
//         error() << "Can't create wayland surface";
//
//         throw ::exception(::error_failed);
//
//      }
//      else
//      {
//
//         information() << "Created wayland surface";
//
//      }
//
//      auto puserinteractionOwner = m_puserinteractionimpl->m_puserinteraction->m_puserinteractionOwner;
//
////      if(puserinteractionOwner)
////      {
////
////         ::pointer < window > pwindowOwner = puserinteractionOwner->window();
////
////         if(pwindowOwner->m_pwlsurface)
////         {
////
////            m_pwlsubsurface = wl_subcompositor_get_subsurface(
////               pdisplaywayaland->m_pwlsubcompositor,
////               m_pwlsurface,
////               pwindowOwner->m_pwlsurface);
////
////            if(m_pwlsubsurface)
////            {
////
////               information() << "Created wayland subsurface";
////
////            }
////            else
////            {
////
////               information() << "Failed to create wayland subsurface";
////
////               wl_subsurface_set_desync(m_pwlsubsurface);
////
////            }
////
////         }
////
////      }
//
//      //wl_surface_add_listener(m_pwlsurface, &g_wl_surface_listener, this);
//
//      pdisplaywayaland->m_windowmap[m_pwlsurface] = this;
//
//      auto pxdgwmbase = pdisplaywayaland->m_pxdgwmbase;
//
//      information() << "pxdgwmbase : " << (::iptr) pxdgwmbase;
//
//      if (!m_pwlsubsurface)
//      {
//
//         m_pxdgsurface = xdg_wm_base_get_xdg_surface(pxdgwmbase, m_pwlsurface);
//
//         if (m_pxdgsurface == NULL)
//         {
//
//            pdisplaywayaland->m_windowmap.erase_item(m_pwlsurface);
//
//            error() << "Can't create shell surface";
//
//            throw ::exception(::error_failed);
//
//         }
//         else
//         {
//
//            information() << "Created shell surface";
//
//         }
//
//         xdg_surface_add_listener(m_pxdgsurface, &xdg_surface_listener, this);
//
//      }
//
//      if (puserinteractionOwner)
//      {
//
//         m_pxdgpositioner = xdg_wm_base_create_positioner(pxdgwmbase);
//
//         auto p = m_puserinteractionimpl->m_puserinteraction->const_layout().sketch().origin();
//
//         if (m_puserinteractionimpl->m_puserinteraction)
//         {
//
//            if (m_puserinteractionimpl->m_puserinteraction->get_parent())
//            {
//
//               m_puserinteractionimpl->m_puserinteraction->get_parent()->client_to_host()(p);
//
//            }
//
//         }
//
//         m_pointWindow = p;
//
//         xdg_positioner_set_offset(m_pxdgpositioner,
//                                   m_pointWindow.x(),
//                                   m_pointWindow.y());
//
//         information() << "xdg_positioner_set_offset " << m_pointWindow;
//
//         ::pointer<window> pwindowOwner = puserinteractionOwner->window();
//
////         if(pwindowOwner->m_pwlsurface)
//         //       {
//
//         /* Assign the popup role */
//         //data->shell_surface.xdg.roleobj.popup.popup = xdg_surface_get_popup(data->shell_surface.xdg.surface,
//         //                                                                  focuseddata->shell_surface.xdg.surface,
//         //                                                                data->shell_surface.xdg.roleobj.popup.positioner);
//
//
//         m_pxdgpopup = xdg_surface_get_popup(m_pxdgsurface, pwindowOwner->m_pxdgsurface, m_pxdgpositioner);
//
//         xdg_popup_add_listener(m_pxdgpopup, &popup_listener_xdg, this);
//
//      }
//      else
//      {
//
//
//         m_pxdgtoplevel = xdg_surface_get_toplevel(m_pxdgsurface);
//
//         if (m_pxdgtoplevel == NULL)
//         {
//
//            pdisplaywayaland->m_windowmap.erase_item(m_pwlsurface);
//
//            error() << "Can't create toplevel";
//
//            throw ::exception(::error_failed);
//
//         }
//         else
//         {
//
//            information() << "Created toplevel";
//
//         }
//
//         xdg_toplevel_add_listener(m_pxdgtoplevel, &g_xdg_toplevel_listener, this);
//
//      }
//
//      //m_pointWindow.x() = x;
//
//      //m_pointWindow.y() = y;
//
//      //auto x = m_pointWindowBestEffort.x();
//
//      //auto y = m_pointWindowBestEffort.y();
//
//      auto x = m_pointWindow.x();
//
//      auto y = m_pointWindow.y();
//
//      auto cx = m_sizeWindow.cx();
//
//      auto cy = m_sizeWindow.cy();
//
//      if (m_pxdgsurface)
//      {
//
//         xdg_surface_set_window_geometry(m_pxdgsurface, x, y, cx, cy);
//
//      }
//
//      auto pimpl = m_puserinteractionimpl;
//
//
//      if (m_pxdgtoplevel)
//      {
//
//         if (!(pimpl->m_puserinteraction->m_ewindowflag & e_window_flag_satellite_window))
//         {
//
//            auto psystem = system()->m_papexsystem;
//
//            string strApplicationServerName = psystem->get_application_server_name();
//
//            xdg_toplevel_set_app_id(m_pxdgtoplevel, strApplicationServerName);
//
//         }
//
//      }
//
//      string strWindowText = pimpl->m_puserinteraction->get_window_text();
//
////         if (strWindowText.has_char())
////         {
////
////            strName = strWindowText;
////
////         }
//
//      //}
//
//      if (strWindowText.has_char())
//      {
//
//         xdg_toplevel_set_title(m_pxdgtoplevel, strWindowText);
//
//      }
//
//      m_timeLastConfigureRequest.Now();
//
//      m_uLastRequestSerial = m_uLastConfigureSerial;
//
//      wl_surface_commit(m_pwlsurface);
//
//      //m_timeLastConfigureRequest += 1_s;
//
//      while (!m_bXdgInitialConfigure)
//      {
//
//         //wl_display_flush(pdisplaywayaland->m_pwldisplay);
//
//         wl_display_dispatch(pdisplaywayaland->m_pwldisplay);
//
//         //wl_display_dispatch(pdisplaywayaland->m_pwldisplay);
//
//         //wl_display_roundtrip(pdisplaywayaland->m_pwldisplay);
//
//      }
//
//   }
//
//
//   void window::__unmap()
//   {
//
//      information() << "windowing_gtk4::window::__unmap";
//
//      if (m_pwlsurface != nullptr)
//      {
//
//         /* Detach any previous buffers before resetting everything, otherwise when
//         * calling this a second time you'll get an annoying protocol error
//         */
//         wl_surface_attach(m_pwlsurface, NULL, 0, 0);
//         wl_surface_commit(m_pwlsurface);
//
//      }
//
//      if (m_pxdgtoplevel != nullptr)
//      {
//
//         xdg_toplevel_destroy(m_pxdgtoplevel);
//
//         m_pxdgtoplevel = nullptr;
//
//      }
//
//
//      if (m_pxdgpopup != nullptr)
//      {
//
//         xdg_popup_destroy(m_pxdgpopup);
//
//         m_pxdgpopup = nullptr;
//
//      }
//
//      if (m_pxdgpositioner != nullptr)
//      {
//
//         xdg_positioner_destroy(m_pxdgpositioner);
//
//         m_pxdgpositioner = nullptr;
//
//      }
//
//      if (m_pxdgsurface != nullptr)
//      {
//
//         xdg_surface_destroy(m_pxdgsurface);
//
//         m_pxdgsurface = nullptr;
//
//      }
//
//      if (m_pwlsubsurface != nullptr)
//      {
//
//         wl_subsurface_destroy(m_pwlsubsurface);
//
//         m_pwlsubsurface = nullptr;
//
//      }
//
//      if (m_pwlsurface != nullptr)
//      {
//
//         wl_surface_destroy(m_pwlsurface);
//
//         m_pwlsurface = nullptr;
//
//      }
//
//   }


void window::set_wm_class(const char* psz)
{
   synchronous_lock synchronouslock(user_synchronization());

   //      m_strWMClass = psz;
   //
   //      display_lock displaylock(x11_display()->Display());
   //
   //      XClassHint classHint;
   //
   //      classHint.res_name = (char *) (const char *) m_strWMClass;
   //
   //      classHint.res_class = (char *) (const char *) m_strWMClass;
   //
   //      XSetClassHint(Display(), Window(), &classHint);
}


i32 window::map_window()
{

   __map();

   return 1;

}


i32 window::unmap_window(bool bWithdraw)
{

   __unmap();

   return 1;

}


bool window::bamf_set_icon()
{
   synchronous_lock synchronouslock(user_synchronization());

   //      auto psystem = system()->m_papexsystem;
   //
   //      auto pnode = psystem->node();
   //
   //      auto papp = get_app();
   //
   //      ::file::path path = pnode->get_desktop_file_path(papp);
   //
   //      informationf("windowing_gtk4::interaction_impl::set_window_text");
   //
   //      //fflush(stdout);
   //
   //      display_lock displaylock(x11_display()->Display());
   //
   //      Atom atomBamfDesktopFile = x11_display()->intern_atom("_BAMF_DESKTOP_FILE", False);
   //
   //      //Atom cardinal = x11_display()->intern_atom("STRING", False);
   //
   //      int status = XChangeProperty(
   //         Display(),
   //         Window(),
   //         atomBamfDesktopFile,
   //         XA_STRING,
   //         8,
   //         PropModeReplace,
   //         (const unsigned char *) (const char *) path,
   //         path.length());
   //
   //      informationf("windowing_gtk4::window::bamf_set_icon END");
   //
   //      //fflush(stdout);
   //
   //      if (status != 0)
   //      {
   //
   //         return false;
   //
   //      }

   return true;
}

//
//   int window::x_change_property(Atom property, Atom type, int format, int mode, const unsigned char * data, int nelements)
//   {
//
//      return XChangeProperty(Display(), Window(), property, type, format, mode, data, nelements);
//
//   }


bool window::set_icon(::image::image* pimage)
{
   // http://stackoverflow.com/questions/10699927/xlib-argb-window-icon
   // http://stackoverflow.com/users/432509/ideasman42
   //
   //#if 0
   //
   //      unsigned int buffer[] =
   //         {
   //         16, 16,
   //         4294901760, 4294901760, 4294901760, 4294901760, 4294901760, 4294901760, 4294901760, 4294901760, 338034905, 3657433343, 0, 184483840, 234881279, 3053453567, 3221225727, 1879048447, 0, 0, 0, 0, 0, 0, 0, 1224737023, 3305111807, 3875537151,0, 0, 2063597823, 1291845887, 0, 67109119, 4294901760, 4294901760, 4294901760, 4294901760, 4294901760, 4294901760, 4294901760, 4294901760, 50266112, 3422552319, 0, 0, 3070230783, 2063597823, 2986344703, 771752191, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3422552319, 0, 0, 3372220671, 1509949695, 704643327, 3355443455, 4294901760, 4294901760, 4294901760, 4294901760, 4294901760, 4294901760, 4294901760, 4294901760, 0, 3422552319, 0, 134152192, 3187671295, 251658495, 0, 3439329535, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3422552319, 0, 0, 2332033279, 1342177535, 167772415, 3338666239, 4294901760, 4294901760, 4294901760, 4294901760, 4294901760, 4294901760, 4294901760, 4294901760, 0, 3422552319, 0, 0, 436207871, 3322085628, 3456106751, 1375731967, 4278255360, 4026597120, 3758161664, 3489726208, 3204513536, 2952855296, 2684419840, 2399207168, 2130771712, 1845559040, 1593900800, 1308688128, 1040252672, 755040000, 486604544, 234946304, 4278255360, 4043374336, 3774938880, 3506503424, 3221290752, 2952855296, 2667642624, 2399207168, 2130771712, 1862336256, 1627453957, 1359017481, 1073805064, 788591627, 503379721, 218169088, 4278255360, 4043374336, 3758161664, 3506503424, 3221290752, 2952855296, 2684419840, 2415984384, 2130771712, 1862336256, 1577123584, 1308688128, 1040252672, 755040000, 486604544, 218169088, 4278190335, 4026532095, 3758096639, 3489661183, 3221225727, 2952790271, 2667577599, 2415919359, 2130706687, 1862271231, 1593835775, 1325400319, 1056964863, 771752191, 520093951, 234881279, 4278190335, 4026532095, 3758096639, 3489661183, 3221225727, 2952790271, 2667577599, 2415919359, 2130706687, 1862271231, 1593835775, 1325400319, 1056964863, 771752191, 503316735, 234881279, 4278190335, 4026532095, 3758096639, 3489661183, 3221225727, 2952790271, 2684354815, 2399142143, 2130706687, 1862271231, 1593835775, 1325400319, 1040187647, 771752191, 520093951, 234881279, 4294901760, 4043243520, 3774808064, 3506372608, 3221159936, 2952724480, 2684289024, 2399076352, 2147418112, 1862205440, 1593769984, 1308557312, 1040121856, 771686400, 503250944, 234815488, 4294901760, 4060020736, 3758030848, 3506372608, 3221159936, 2952724480, 2684289024, 2415853568, 2130640896, 1862205440, 1593769984, 1308557312, 1040121856, 771686400, 503250944, 234815488, 4294901760, 4043243520, 3774808064, 3489595392, 3237937152, 2952724480, 2684289024, 2415853568, 2147418112, 1862205440, 1593769984, 1325334528, 1056899072, 788463616, 503250944, 234815488,
   //         32, 32,
   //         4294901760, 4294901760, 4294901760, 4294901760, 4294901760, 4294901760, 4294901760, 4294901760, 4294901760, 4294901760, 4294901760, 4294901760, 4294901760, 4294901760, 4294901760, 4294901760, 0, 0, 0, 0, 0, 0, 0, 0, 0, 268369920, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4294901760, 4294901760, 4294901760, 4294901760, 4294901760, 4294901760, 4294901760, 4294901760, 4294901760, 4294901760, 4294901760, 4294901760, 4294901760, 4294901760, 4294901760, 4294901760, 1509949695, 3120562431, 4009754879, 4194304255, 3690987775, 2130706687, 83886335, 0, 50331903, 1694499071, 3170894079, 3992977663, 4211081471, 3657433343, 1879048447, 16777471, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3087007999, 2281701631, 1191182591, 1040187647, 2030043391, 4127195391, 2566914303, 0, 16777471, 3254780159, 2181038335, 1191182591, 973078783, 2030043391,4177527039, 2130706687, 4294901760, 4294901760, 4294901760, 4294901760, 4294901760, 4294901760, 4294901760, 4294901760, 4294901760, 4294901760, 4294901760, 4294901760, 4294901760, 4294901760, 4294901760, 4294901760, 0, 0, 0, 0, 0, 2214592767, 4093640959, 0, 0, 0, 0, 0, 0, 0, 2298478847, 3909091583, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2214592767, 3607101695, 0, 0, 0, 0, 0, 0, 0, 1946157311, 4093640959, 4294901760, 4294901760, 4294901760, 4294901760, 4294901760, 4294901760, 4294901760, 4294901760, 4294901760, 4294901760, 4294901760, 4294901760, 4294901760, 4294901760, 4294901760, 4294901760, 0, 0, 536871167, 1191182591, 2281701631,3019899135, 637534463, 0, 0, 0, 100597760, 251592704, 33488896, 0, 3321889023, 2919235839, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2550137087, 4278190335, 4278190335, 3405775103, 570425599, 0, 0, 0, 0, 0, 0, 2046820607, 4043309311, 620757247, 4294901760, 4294901760, 4294901760, 4294901760, 4294901760, 4294901760, 4294901760, 4294901760, 4294901760, 4294901760, 4294901760, 4294901760, 4294901760, 4294901760, 4294901760, 4294901760, 33488896, 0, 0, 218104063, 1291845887, 3841982719, 3388997887, 0, 0, 0, 0, 0, 1996488959, 4093640959, 1073742079, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1761607935, 4278190335, 150995199, 0, 0, 67109119, 2550137087, 3909091583, 889192703, 0, 0, 4294901760, 4294901760, 4294901760, 4294901760, 4294901760, 4294901760, 4294901760, 4294901760, 4294901760, 4294901760, 4294901760, 4294901760, 4294901760, 4294901760, 4294901760, 4294901760, 0, 0, 0, 0, 0, 2181038335, 3925868799, 0, 0, 218104063, 3070230783, 3623878911, 570425599, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 805306623, 3288334591, 1795162367, 1040187647, 1023410431, 2231369983, 4211081471, 1694499071, 0, 369099007, 3456106751, 3825205503, 1174405375, 872415487, 872415487, 872415487, 872415487, 4294901760, 4294901760, 4294901760, 4294901760, 4294901760, 4294901760, 4294901760, 4294901760, 4294901760, 4294901760, 4294901760, 4294901760, 4294901760, 4294901760, 4294901760, 4293984270, 2046951677, 3422552319, 4110418175, 4177527039, 3405775103, 1409286399, 0, 0, 1409286399, 4278190335, 4278190335, 4278190335, 4278190335, 4278190335, 4278190335, 4278190335, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4294901760, 4294901760, 4294901760, 4294901760, 4294901760, 4294901760, 4294901760, 4294901760,4294901760, 4294901760, 4294901760, 4294901760, 4294901760, 4294901760, 4294901760, 4294901760, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4278255360, 4144037632, 4009819904, 3875602176, 3741384448, 3607166720, 3472948992, 3338731264, 3204513536, 3053518592, 2936078080, 2801860352, 2650865408, 2516647680, 2382429952, 2264989440, 2113994496, 1996553984, 1862336256, 1728118528, 1577123584, 1459683072, 1325465344, 1191247616, 1040252672, 922812160, 771817216, 637599488, 503381760, 385941248, 234946304, 100728576, 4278255360, 4144037632, 4009819904, 3875602176, 3724607232, 3607166720, 3472948992, 3338731264, 3204513536, 3070295808, 2936078080, 2801860352, 2667642624, 2516647680, 2399207168, 2264989440, 2130771712, 1996553984, 1845559040, 1728118528, 1593900800, 1459683072, 1308688128, 1191247616, 1057029888, 922812160, 788594432, 637599488, 503381760, 369164032, 234946304, 117505792, 4278255360, 4144037632, 4009819904, 3875602176, 3741384448, 3607166720, 3472948992, 3338731264, 3204513536, 3053518592, 2919300864, 2801860352, 2650865408, 2533424896, 2399207168, 2264989440, 2113994496, 1996553984, 1862336256, 1728118528,1593900800, 1459683072, 1325465344, 1191247616, 1040252672, 906034944, 771817216, 654376704, 503381760, 369164032, 234946304, 117505792, 4278255360, 4144037632, 4009819904, 3858824960, 3741384448, 3607166720, 3472948992, 3338731264, 3204513536, 3070295808, 2936078080, 2801860352, 2667642624, 2533424896, 2382429952, 2264989440, 2130771712, 1979776768, 1862336256, 1728118528, 1577123584, 1442905856, 1325465344, 1191247616, 1040252672, 922812160, 771817216, 637599488, 503381760, 369164032, 234946304, 100728576, 4278255360, 4144037632, 4009819904, 3875602176, 3741384448, 3607166720, 3472948992, 3338731264, 3204513536, 3070295808, 2919300864, 2801860352, 2667642624, 2533424896, 2399207168, 2264989440, 2113994496, 1996553984, 1862336256, 1728118528, 1593900800, 1442905856, 1342241795, 1174470400, 1057029888, 906034944, 788594432, 654376704, 503381760, 385941248, 251723520, 100728576, 4278190335, 4160749823, 4026532095, 3892314367, 3741319423, 3623878911, 3472883967, 3338666239, 3221225727, 3070230783, 2952790271, 2818572543, 2667577599, 2533359871, 2399142143, 2264924415, 2147483903, 1996488959, 1862271231, 1728053503, 1593835775, 1459618047, 1325400319, 1191182591, 1056964863, 922747135, 788529407, 654311679, 520093951,385876223, 251658495, 117440767, 4278190335, 4160749823, 4026532095, 3892314367, 3741319423, 3623878911, 3489661183, 3355443455, 3221225727, 3087007999, 2936013055, 2801795327, 2667577599, 2533359871, 2399142143, 2281701631, 2130706687, 1996488959, 1862271231, 1728053503, 1593835775,1459618047, 1325400319, 1191182591, 1056964863, 922747135, 788529407, 654311679, 520093951, 385876223, 234881279, 100663551, 4278190335, 4160749823, 4026532095, 3892314367, 3758096639, 3623878911, 3489661183, 3355443455, 3221225727, 3087007999, 2936013055, 2801795327, 2667577599, 2550137087, 2415919359, 2264924415, 2130706687, 1996488959, 1862271231, 1728053503, 1593835775, 1459618047, 1325400319, 1191182591, 1056964863, 922747135, 788529407, 654311679, 503316735, 369099007, 251658495, 100663551, 4278190335, 4160749823, 4026532095, 3892314367, 3758096639, 3623878911, 3489661183, 3355443455, 3204448511, 3087007999, 2936013055, 2818572543, 2667577599, 2533359871, 2399142143, 2264924415, 2130706687, 1996488959, 1879048447, 1728053503, 1593835775, 1459618047, 1325400319, 1191182591, 1056964863, 922747135, 788529407, 654311679, 520093951, 385876223, 251658495, 117440767, 4278190335, 4160749823, 4026532095, 3892314367, 3758096639, 3623878911, 3489661183, 3355443455, 3221225727, 3087007999, 2952790271, 2818572543, 2667577599, 2533359871, 2399142143, 2264924415, 2147483903, 2013266175, 1862271231, 1744830719, 1610612991, 1476395263, 1342177535, 1191182591, 1056964863, 922747135, 788529407, 654311679, 520093951, 385876223, 251658495, 100663551, 4294901760, 4160684032, 4026466304, 3909025792, 3774808064, 3623813120, 3489595392, 3355377664, 3237937152, 3103719424, 2952724480, 2818506752, 2684289024, 2550071296, 2415853568, 2281635840, 2147418112, 2013200384, 1878982656, 1744764928, 1593769984, 1476329472,1325334528, 1207894016, 1056899072, 939458560, 788463616, 654245888, 520028160, 385810432, 251592704, 117374976, 4294901760, 4177461248, 4043243520, 3909025792, 3774808064, 3640590336, 3506372608, 3355377664, 3221159936, 3086942208, 2952724480, 2818506752, 2701066240, 2550071296, 2415853568, 2281635840, 2147418112, 2013200384, 1878982656, 1727987712, 1610547200, 1476329472, 1325334528, 1191116800, 1073676288, 922681344, 788463616, 654245888, 520028160, 385810432, 251592704, 100597760, 4294901760, 4177461248, 4043243520, 3909025792, 3774808064, 3640590336, 3489595392, 3372154880, 3237937152, 3103719424, 2952724480, 2818506752, 2700935170, 2550071296, 2415853568, 2281635840, 2147418112, 2013200384, 1878982656, 1744764928, 1610547200, 1459552256, 1342111744, 1191116800, 1056899072, 922681344, 788463616, 671023104, 520028160, 385810432, 251592704, 100597760, 4294901760, 4177461248, 4043243520, 3909025792, 3774808064, 3640590336, 3489595392, 3372154880, 3237937152, 3086942208, 2969501696, 2818506752, 2684289024, 2550071296, 2432630784, 2281635840, 2147418112, 2013200384, 1862205440, 1744764928, 1610547200, 1476329472, 1342111744, 1191116800, 1056899072, 922681344, 788463616, 654245888, 520028160, 385810432, 251592704, 117374976, 4294901760, 4177461248, 4043243520, 3909025792, 3774808064, 3623813120, 3506372608, 3372154880, 3237937152, 3103719424, 2952724480, 2835283968, 2684289024, 2550071296, 2432630784, 2281635840, 2147418112, 2046492676, 1862205440, 1744764928, 1610547200, 1476329472, 1342111744,1207894016, 1056899072, 939458560, 788463616, 654245888, 536281096, 385810432, 251592704, 134152192,
   //         };
   //
   //      display_lock displaylock(x11_display()->Display());
   //
   //      int iScreen = DefaultScreen(d);
   //
   //      Atom net_wm_icon = x11_display()->intern_atom("_NET_WM_ICON", False);
   //
   //      Atom cardinal = x11_display()->intern_atom("CARDINAL", False);
   //
   //      int length = 2 + 16 * 16 + 2 + 32 * 32;
   //
   //      int status = XChangeProperty(Display(), w->Window(), net_wm_icon, cardinal, 32, PropModeReplace, (const unsigned char*) buffer, length);
   //
   //      if(status != 0)
   //      {
   //
   //         return false;
   //
   //      }
   //
   //#elif 1
   //
   //      auto image1 = image()->create_image({32, 32});
   //
   //      if (image1.nok())
   //      {
   //
   //         return false;
   //
   //      }
   //
   //      image1->g()->set_interpolation_mode(::draw2d::e_interpolation_mode_high_quality_bicubic);
   //
   //      {
   //
   //         ::image::image_source imagesource(pimage->g(), pimage->rectangle());
   //
   //         rectangle_f64 rectangle(image1->rectangle());
   //
   //         ::image::image_drawing_options imagedrawingoptions(rectangle);
   //
   //         ::image::image_drawing imagedrawing(imagedrawingoptions, imagesource);
   //
   //         //getfileimage.m_iImage = m_pimagelist[16]->set(getfileimage.m_iImage, imagedrawing);
   //
   //         image1->g()->draw(imagedrawing);
   //
   //      }
   //
   //      memory m(m_puserinteractionimpl->m_puserinteraction->get_app());
   //
   //      int length = 2 + image1->area();
   //
   //      m.set_size(length * 4);
   //
   //      unsigned int * pcr = (unsigned int *) m.data();
   //
   //      pcr[0] = image1->width();
   //
   //      pcr[1] = image1->height();
   //
   //      int c = image1->area();
   //
   //      for (int i = 0; i < c; i++)
   //      {
   //
   //         pcr[i + 2] = image1->image32()[i].m_u32;
   //
   //      }
   //
   //      windowing_output_debug_string("\nwindow::set_icon");
   //
   //      synchronous_lock synchronouslock(user_synchronization());
   //
   //      display_lock displaylock(x11_display()->Display());
   //
   //      Atom net_wm_icon = x11_display()->intern_atom("_NET_WM_ICON", False);
   //
   //      Atom cardinal = x11_display()->intern_atom("CARDINAL", False);
   //
   //      int status = x_change_property(net_wm_icon, cardinal, 32, PropModeReplace, (const unsigned char *) pcr, length);
   //
   //      if (status == BadAlloc)
   //      {
   //
   //
   //      } else if (status != 0)
   //      {
   //
   //         return false;
   //
   //      }
   //
   //      windowing_output_debug_string("\nwindow::set_icon END");
   //
   //      fflush(stdout);
   //
   //#else
   //
   //      image d1(w->m_puserinteractionimpl->m_puserinteraction->create_new, this);
   //
   //      if(!d1->create(24, 24))
   //      {
   //
   //         return false;
   //
   //      }
   //
   //      d1->get_graphics()->set_interpolation_mode(e_interpolation_mode_high_quality_bicubic);
   //
   //      d1->get_graphics()->StretchBlt(0, 0, d1.width(), d1.height(), point->get_graphics(), 0, 0, point.width(), point.height());
   //
   //      image d2(w->m_puserinteractionimpl->m_puserinteraction->create_new, this);
   //
   //      if(!d2->create(54, 54))
   //      {
   //
   //         return false;
   //
   //      }
   //
   //      d2->get_graphics()->set_interpolation_mode(e_interpolation_mode_high_quality_bicubic);
   //
   //      d2->get_graphics()->StretchBlt(0, 0, d2.width(), d2.height(), point->get_graphics(), 0, 0, point.width(), point.height());
   //
   //      memory m(w->m_puserinteractionimpl->m_puserinteraction->get_context_application());
   //
   //      int length = 2 + d1->area() + 2 + d2->area();
   //
   //      m.set_size(length * 4);
   //
   //      unsigned int * pcr = (unsigned int *) m.get_data();
   //
   //      pcr[0] = d1.width();
   //
   //      pcr[1] = d1.height();
   //
   //      int c = d1->area();
   //
   //      for(int i = 0; i < c; i++)
   //      {
   //
   //         pcr[i+2] = d1->m_pcolorref[i];
   //
   //      }
   //
   //      memsize o;
   //
   //      o = 2 + d1->area();
   //
   //      pcr[o] = d2.width();
   //
   //      pcr[o+1] = d2.height();
   //
   //      c = d2->area();
   //
   //      for(int i = 0; i < c; i++)
   //      {
   //
   //         pcr[i+o+2] = d2->m_pcolorref[i];
   //
   //      }
   //
   //      Display *display = w->display();
   //
   //      Atom net_wm_icon = XInternAtom(display, "_NET_WM_ICON", False);
   //
   //      Atom cardinal = XInternAtom(display, "CARDINAL", False);
   //
   //      int status = XChangeProperty(display, w->Window(), net_wm_icon, cardinal, 32, PropModeReplace, (const unsigned char*) pcr, length);
   //
   //      if(status != 0)
   //      {
   //
   //         //file_put_contents("/home/camilo/window.txt", as_string((int)w->Window()));
   //         return false;
   //
   //      }
   //#endif
   return true;
}


i32 window::store_name(const char* psz)
{
   windowing_output_debug_string("\nwindow::store_name");

   //      synchronous_lock synchronouslock(user_synchronization());
   //
   //      display_lock displaylock(x11_display()->Display());
   //
   //      int i = XStoreName(Display(), Window(), psz);
   //
   //      windowing_output_debug_string("\nwindow::store_name END");

   return 0;
}


i32 window::select_input(i32 iInput)
{
   windowing_output_debug_string("\nwindow::select_input");

   synchronous_lock synchronouslock(user_synchronization());

   //      display_lock displaylock(x11_display()->Display());
   //
   //      int i = XSelectInput(Display(), Window(), iInput);
   //
   //      windowing_output_debug_string("\nwindow::select_input END");

   return 0;
}


i32 window::select_all_input()
{
   windowing_output_debug_string("\nwindow::select_all_input");

   synchronous_lock synchronouslock(user_synchronization());

   //      display_lock displaylock(x11_display()->Display());
   //
   //      int i = select_input(ExposureMask | ButtonPressMask);
   //
   //      windowing_output_debug_string("\nwindow::select_all_input");

   return 0;
}


void window::post_nc_destroy()
{
   if (!::is_null(this))
   {
      m_pwindowing->erase_window(this);
   }
}


void window::set_user_interaction(::user::interaction_impl* pimpl)
{
   //      single_lock sl(ms_pmutex, true);
   //
   //      if (::is_null(this))
   //      {
   //
   //         throw ::exception(::exception("error, m_pdata cannot be nullptr to ::oswindow::set_user_interaction"));
   //
   //      }

   m_puserinteractionimpl = pimpl;

   m_htask = pimpl->get_app()->get_os_handle();

   m_pmessagequeue = pimpl->m_puserinteraction->m_pthreadUserInteraction->get_message_queue();

   //oswindow_assign(this, pimpl);
}


//   bool window::is_child(::oswindow oswindow)
//   {
//
//      if (oswindow == nullptr || oswindow->m_puserinteractionimpl == nullptr ||
//          oswindow->m_puserinteractionimpl->m_puserinteraction == nullptr)
//      {
//
//         return false;
//
//      }
//
//      if (m_puserinteractionimpl == nullptr || m_puserinteractionimpl->m_puserinteraction == nullptr)
//      {
//
//         return false;
//
//      }
//
//      return m_puserinteractionimpl->m_puserinteraction->is_child(oswindow->m_puserinteractionimpl->m_puserinteraction);
//
//   }
//
//
//   ::windowing::window * window::get_parent() const
//   {
//
//      return nullptr;
//
//   }


//virtual ::Window get_parent_handle();
oswindow window::get_parent_oswindow() const
{
   return nullptr;
}


//   ::point_i32 window::get_mouse_cursor_host_position()
//   {
//
//      return m_pointCursor;
//
//   }
//
//
//   ::point_i32 window::get_mouse_cursor_absolute_position()
//   {
//
//      return m_pointCursorHost;
//
//   }


::windowing_gtk4::windowing* window::gtk4_windowing()
{

      return dynamic_cast < ::windowing_gtk4::windowing * > (m_pwindowing.m_p);

}


::windowing_gtk4::display* window::gtk4_display()
{

      return dynamic_cast < ::windowing_gtk4::display * > (m_pdisplaybase.m_p);

}



//   ::Window window::get_parent_handle()
//   {
//
//      //single_lock slOsWindow(s_pmutex, true);
//
//      //if (::is_null(this))
//        // return 0;
//
//      return m_parent;
//
//   }


//   oswindow window::get_parent()
//   {
//
//      if (::is_null(this))
//      {
//
//         return nullptr;
//
//      }
//
//      return nullptr;
//
//   }


void window::set_parent(::windowing::window* pwindowNewParent)
{
   if (::is_null(this))
   {
      throw ::exception(error_failed);
   }

   if (::is_null(pwindowNewParent))
   {
      throw ::exception(error_failed);
   }

   auto pwindowx11NewParent = dynamic_cast<::windowing_gtk4::window *>(pwindowNewParent);

   if (::is_null(pwindowx11NewParent))
   {
      throw ::exception(error_null_pointer);
   }

   synchronous_lock synchronouslock(user_synchronization());

   //      display_lock displaylock(x11_display()->Display());
   //
   //      XReparentWindow(Display(), Window(), pwindowx11NewParent->Window(), 0, 0);

   //return ::success;
}


///// Post an event from the client to the X server
//   void window::send_client_event(Atom atom, unsigned int numArgs, ...)
//   {
//
//      XEvent xevent;
//
//      unsigned int i;
//
//      va_list argp;
//
//      va_start(argp, numArgs);
//
//      zero(xevent);
//
//      xevent.xclient.type = ClientMessage;
//      xevent.xclient.serial = 0;
//      xevent.xclient.send_event = False;
//      xevent.xclient.display = Display();
//      xevent.xclient.window = Window();
//      xevent.xclient.message_type = atom;
//      xevent.xclient.format = 32;
//
//      for (i = 0; i < numArgs; i++)
//      {
//
//         xevent.xclient.data.l[i] = va_arg(argp, int);
//
//      }
//
//      XSendEvent(Display(), RootWindow(Display(), x11_display()->m_iScreen), False,
//                 SubstructureRedirectMask | SubstructureNotifyMask, &xevent);
//
//      va_end(argp);
//
//   }
//
//
//   Atom get_window_long_atom(i32 nIndex);
//
//// Change _NET_WM_STATE if Window is Mapped
//   void window::_mapped_net_state_unlocked(bool add, int iScreen, Atom state1, Atom state2)
//   {
//
//      //synchronous_lock synchronouslock(user_synchronization());
//
//      XClientMessageEvent xclient;
//
//#define _NET_WM_STATE_REMOVE        0    /* remove/unset property */
//#define _NET_WM_STATE_ADD           1    /* add/set property */
//#define _NET_WM_STATE_TOGGLE        2    /* toggle property  */
//
//      zero(xclient);
//      xclient.type = ClientMessage;
//      xclient.window = Window();
//      xclient.message_type = x11_display()->intern_atom("_NET_WM_STATE", False);
//      xclient.format = 32;
//      xclient.data.l[0] = add ? _NET_WM_STATE_ADD : _NET_WM_STATE_REMOVE;
//      xclient.data.l[1] = state1;
//      xclient.data.l[2] = state2;
//      xclient.data.l[3] = 1; /* source indication */
//      xclient.data.l[4] = 0;
//
//      if(add)
//      {
//
//         if(state1 != None)
//         {
//            m_atomaNetWmState.add_unique(state1);
//         }
//         if(state2 != None)
//         {
//            m_atomaNetWmState.add_unique(state2);
//         }
//
//      }
//      else
//      {
//         if(state1 != None)
//         {
//            m_atomaNetWmState.erase(state1);
//         }
//         if(state2 != None)
//         {
//            m_atomaNetWmState.erase(state2);
//         }
//
//      }
//      XSendEvent(Display(), RootWindow(Display(), iScreen), False, SubstructureRedirectMask | SubstructureNotifyMask,
//                 (XEvent *) &xclient);
//      //     XSendEvent(Display(), RootWindow(Display(), iScreen), False, 0, (XEvent *) &xclient);
//
//
//
//
//
//   }
//
//
//   void window::unmapped_net_state_raw(Atom atom1, ...)
//   {
//
//      synchronous_lock synchronouslock(user_synchronization());
//
//      XEvent xevent;
//
//      unsigned int i;
//
//      va_list argp;
//
//      va_start(argp, atom1);
//
//      zero(xevent);
//
//      array<Atom> atoms;
//
//      atoms.add(atom1);
//
//      while (true)
//      {
//
//         Atom atom = va_arg(argp, int);
//
//         if (atom == 0)
//         {
//
//            break;
//
//         }
//
//         atoms.add(atom);
//
//      }
//
//      if (atoms.has_elements())
//      {
//
//         XChangeProperty(Display(), Window(), x11_display()->intern_atom("_NET_WM_STATE", False),
//                         XA_ATOM, 32, PropModeReplace,
//                         (const unsigned char *) atoms.data(), atoms.size());
//      } else
//      {
//
//         XDeleteProperty(Display(), Window(), x11_display()->intern_atom("_NET_WM_STATE", False));
//
//      }
//
//      va_end(argp);
//
//   }
//
//
//   /// this function should be called in user/main thread
//   void window::show_window(const ::e_display & edisplay, const ::e_activation & eactivation)
//   {
//
//      aaa_user_post([this, edisplay, eactivation]()
//                                      {
//
//                                         windowing_output_debug_string("::window::show_window 1");
//
//                                         synchronous_lock synchronouslock(user_synchronization());
//
//                                         display_lock displaylock(x11_display()->Display());
//
//                                         _show_window_unlocked(edisplay, eactivation);
//
////         XWindowAttributes attr;
////
////         if (!XGetWindowAttributes(Display(), Window(), &attr))
////         {
////
////            windowing_output_debug_string("::window::show_window 1.2");
////
////            return;
////
////            //return false;
////
////         }
////
////         if (edisplay == e_display_zoomed)
////         {
////
////            int iMapState = attr.map_state;
////
////            if (iMapState != IsViewable)
////            {
////
////               XMapWindow(Display(), Window());
////
////            }
////
////            auto atomMaxH = x11_display()->intern_atom(::x11::e_atom_net_wm_state_maximized_horz, false);
////
////            auto atomMaxP = x11_display()->intern_atom(::x11::e_atom_net_wm_state_maximized_penn, false);
////
////            mapped_net_state_raw(true, x11_display()->m_iScreen, atomMaxH, atomMaxP);
////
////
////
////
////         }
//         if (edisplay == e_display_iconic)
//         {
//
//            //wm_iconify_window();
//            xdg_toplevel_set_minimized(m_pxdgtoplevel);
//
//        }
////         else if (::is_visible(edisplay))
////         {
////
////            if (attr.map_state == IsUnmapped)
////            {
////
////               XMapWindow(Display(), Window());
////
////            }
////
////            wm_state_clear_raw(false);
////
////         }
////         else
////         {
////
////            if (attr.map_state != IsUnmapped)
////            {
////
////               XWithdrawWindow(Display(), Window(), Screen());
////
////            }
////
////         }
////
////         windowing_output_debug_string("::window::show_window 2");
//
//                                         //return true;
//
//                                      }
//
//      );
//
//      //return ::success;
//
//   }
//
//
//   void window::_show_window_unlocked(const ::e_display & edisplay, const ::e_activation & eactivation)
//   {
//
//      //aaa_user_post([this, edisplay, eactivation]()
//      //{
//
//      windowing_output_debug_string("::window::show_window 1");
//
////      synchronous_lock synchronouslock(user_synchronization());
////
////      display_lock displaylock(x11_display()->Display());
//
//      XWindowAttributes attr;
//
//      if (!XGetWindowAttributes(Display(), Window(), &attr))
//      {
//
//         windowing_output_debug_string("::window::show_window 1.2");
//
//         return;
//
//         //return false;
//
//      }
//
//      if (edisplay == e_display_zoomed)
//      {
//
//         int iMapState = attr.map_state;
//
//         if (iMapState != IsViewable)
//         {
//
//            XMapWindow(Display(), Window());
//
//         }
//
//         auto atomMaxH = x11_display()->intern_atom(::x11::e_atom_net_wm_state_maximized_horz, false);
//
//         auto atomMaxP = x11_display()->intern_atom(::x11::e_atom_net_wm_state_maximized_penn, false);
//
//         _mapped_net_state_unlocked(true, x11_display()->m_iScreen, atomMaxH, atomMaxP);
//
//      } else if (edisplay == e_display_iconic)
//      {
//
//         wm_iconify_window();
//
//      } else if (::is_visible(edisplay))
//      {
//
//         if (attr.map_state == IsUnmapped)
//         {
//
//            XMapWindow(Display(), Window());
//
//         }
//
//         _wm_state_clear_unlocked(false);
//
//      } else
//      {
//
//         if (attr.map_state != IsUnmapped)
//         {
//
//            XWithdrawWindow(Display(), Window(), Screen());
//
//         }
//
//      }
//
//      windowing_output_debug_string("::window::show_window 2");
//
//      //return true;
//
//      //}
//
//      //);
//
//      //return ::success;
//
//   }


void window::full_screen(const ::rectangle_i32& rectangle)
{
   ::rectangle_i32 rBest;

      auto pgtk4display = gtk4_display();

   int iMonitor = pgtk4display->get_best_monitor(&rBest, rectangle);

   windowing_output_debug_string("::window::full_screen 1");

   synchronous_lock synchronouslock(user_synchronization());

   //      display_lock displaylock(x11_display()->Display());
   //
   ////      if (x11_display()->is_null())
   ////      {
   ////
   ////         windowing_output_debug_string("::window::full_screen 1.1");
   ////
   ////         return;
   ////
   ////      }
   //
   //      XWindowAttributes attr;
   //
   //      if (!XGetWindowAttributes(Display(), Window(), &attr))
   //      {
   //
   //         windowing_output_debug_string("::window::full_screen 1.2");
   //
   //         fflush(stdout);
   //
   //         throw ::exception(error_failed);
   //
   //      }
   //
   //      ::rectangle_i32 rWindow;
   //
   //      rWindow.left() = attr.x;
   //      rWindow.top() = attr.y;
   //      rWindow.right() = attr.x + attr.width;
   //      rWindow.bottom() = attr.y + attr.height;
   //
   //      if (rBest != rWindow)
   //      {
   //
   //         m_puserinteractionimpl->m_puserinteraction->place(rBest);
   //
   //         XMoveResizeWindow(Display(), Window(), rBest.left(), rBest.top(), rBest.width(), rBest.height());
   //
   //      }
   //
   //      if (attr.map_state == IsViewable)
   //      {
   //
   //         _mapped_net_state_unlocked(true, Screen(),
   //                                    x11_display()->intern_atom(::x11::e_atom_net_wm_state_fullscreen, false), 0);
   //
   //      } else
   //      {
   //
   //         unmapped_net_state_raw(x11_display()->intern_atom(::x11::e_atom_net_wm_state_fullscreen, false), 0);
   //
   //         XMapWindow(Display(), Window());
   //
   //      }
   //
   //      windowing_output_debug_string("::window::full_screen 2");
   //
   //      ::fflush(stdout);
   //
   //      //return ::success;
}


void window::exit_iconify()
{
   synchronous_lock synchronouslock(user_synchronization());

   //      display_lock displaylock(x11_display()->Display());
   //
   //      XWindowAttributes attr;
   //
   //      if (!XGetWindowAttributes(Display(), Window(), &attr))
   //      {
   //
   //         windowing_output_debug_string("::window::exit_full_screen 1.2");
   //
   //         fflush(stdout);
   //
   //         throw ::exception(error_failed);
   //
   //      }
   //
   //      if (attr.map_state == IsViewable)
   //      {
   //
   //         _mapped_net_state_unlocked(false, Screen(),
   //                                    x11_display()->intern_atom(::x11::e_atom_net_wm_state_hidden, false), 0);
   //
   //      }
   //
   //      //return ::success;
}


void window::exit_full_screen()
{
   synchronous_lock synchronouslock(user_synchronization());

   //      display_lock displaylock(x11_display()->Display());
   //
   //      XWindowAttributes attr;
   //
   //      if (!XGetWindowAttributes(Display(), Window(), &attr))
   //      {
   //
   //         windowing_output_debug_string("::window::exit_full_screen 1.2");
   //
   //         fflush(stdout);
   //
   //         throw ::exception(error_failed);
   //
   //      }
   //
   //      if (attr.map_state == IsViewable)
   //      {
   //
   //         _mapped_net_state_unlocked(false, Screen(), x11_display()->intern_atom("_NET_WM_STATE_FULLSCREEN", false), 0);
   //
   //      }
   //
   //      //return ::success;
}


void window::exit_zoomed()
{
   //      synchronous_lock sl(user_synchronization());
   //
   //      display_lock displaylock(x11_display()->Display());
   //
   //      XWindowAttributes attr;
   //
   //      if (!XGetWindowAttributes(Display(), Window(), &attr))
   //      {
   //
   //         windowing_output_debug_string("::window::exit_zoomed 1.2");
   //
   //         fflush(stdout);
   //
   //         throw ::exception(error_failed);
   //
   //      }
   //
   //      if (attr.map_state == IsViewable)
   //      {
   //
   //         mapped_net_state_raw(false, Screen(),
   //                              x11_display()->intern_atom(::x11::e_atom_net_wm_state_maximized_horz, false),
   //                              x11_display()->intern_atom(::x11::e_atom_net_wm_state_maximized_penn, false));
   //
   //      }

   //return success;
}


//   iptr window::get_window_long_ptr(i32 nIndex)
//   {
//
//      return m_puserinteractionimpl->get_window_long_ptr(nIndex);
//
//   }


//   iptr window::set_window_long_ptr(i32 nIndex, iptr i)
//   {
//
//      return m_puserinteractionimpl->set_window_long_ptr(nIndex, i);
//
//      //iptr iOld = m_plongmap->operator[](nIndex);
//
//      //   if(nIndex == GWL_EXSTYLE)
//      //   {
//      //
//      //      if(is_different((l & WS_EX_TOOLWINDOW), (m_plongmap->operator[](nIndex) & WS_EX_TOOLWINDOW)))
//      //      {
//      //
//      //         wm_toolwindow(this, (l & WS_EX_TOOLWINDOW) != 0);
//      //
//      //      }
//      //
//      //   }
//
//      //m_plongmap->operator[](nIndex) = i;
//
//      //return iOld;
//
//   }


bool window::client_to_screen(::point_i32* ppoint)
{
   return true;
}


bool window::screen_to_client(::point_i32* ppoint)
{
   return true;
}


//   bool window::get_state(long & lState)
//   {
//
//      windowing_output_debug_string("::window::get_state 1");
//
//      synchronous_lock synchronouslock(user_synchronization());
//
//      display_lock displaylock(x11_display()->Display());
//
//      return _get_wm_state_unlocked(lState);
//
//   }
//
//
//   bool window::_get_wm_state_unlocked(long & lState)
//   {
//
//      static const long WM_STATE_ELEMENTS = 2L;
//
//      if (x11_display()->m_atomWmState == None)
//      {
//
//         x11_display()->m_atomWmState = x11_display()->intern_atom("WM_STATE", false);
//
//      }
//
//      Atom actual_type = 0;
//
//      i32 actual_format = 0;
//
//      unsigned long nitems = 0;
//
//      unsigned long leftover = 0;
//
//      unsigned char * p = nullptr;
//
//      auto atomWmState = x11_display()->m_atomWmState;
//
//      ::i32 status = XGetWindowProperty(Display(), Window(), atomWmState, 0L,
//                                        WM_STATE_ELEMENTS, False, AnyPropertyType,
//                                  &actual_type,
//                                  &actual_format, &nitems, &leftover, &p);
//
//      if (status != 0)
//      {
//
//         windowing_output_debug_string("::window::_get_state_unlocked 2");
//
//         return false;
//
//      }
//
//      long lStatus = -1;
//
//      if (p != nullptr)
//      {
//
//         lStatus = (long) *p;
//
//      }
//
//      XFree(p);
//
//      windowing_output_debug_string("::window::_get_state_unlocked 1.1");
//
//      lState = lStatus;
//
//      return true;
//
//   }


bool window::is_iconic()
{
   //#ifdef XDISPLAY_LOCK_LOG
   //
   //      b_prevent_xdisplay_lock_log = true;
   //
   //#endif
   //
   //      long lState = -1;
   //
   //      if(!get_state(lState))
   //      {
   //
   //         return false;
   //
   //      }
   //
   //      bool bIconic = lState == IconicState;
   //
   //#ifdef XDISPLAY_LOCK_LOG
   //
   //      b_prevent_xdisplay_lock_log = false;
   //
   //#endif
   //
   //      return lState;
   return false;
}


bool window::is_window_visible()
{
   windowing_output_debug_string("::window::is_window_visible 1");

   synchronous_lock synchronouslock(user_synchronization());

   //      display_lock displaylock(x11_display()->Display());
   //
   //      if (x11_display()->is_null())
   //      {
   //
   //         windowing_output_debug_string("::window::is_window_visible 1.1");
   //
   //         return false;
   //
   //      }
   //
   //      return _is_window_visible_unlocked();


   return true;
   //      XWindowAttributes attr;
   //
   //      if (!XGetWindowAttributes(Display(), Window(), &attr))
   //      {
   //
   //         windowing_output_debug_string("::window::is_window_visible 1.2");
   //
   //         return false;
   //
   //      }
   //
   //      windowing_output_debug_string("::window::is_window_visible 2");
   //
   //      return attr.map_state == IsViewable;
}


bool window::_is_window_visible_unlocked()
{
   //      windowing_output_debug_string("::window::is_window_visible 1");
   //
   //      synchronous_lock synchronouslock(user_synchronization());
   //
   //      display_lock displaylock(x11_display()->Display());
   //
   //      if (x11_display()->is_null())
   //      {
   //
   //         windowing_output_debug_string("::window::is_window_visible 1.1");
   //
   //         return false;
   //
   //      }

   //      XWindowAttributes attr;
   //
   //      if (!XGetWindowAttributes(Display(), Window(), &attr))
   //      {
   //
   //         windowing_output_debug_string("::window::is_window_visible 1.2");
   //
   //         return false;
   //
   //      }
   //
   //      windowing_output_debug_string("::window::is_window_visible 2");
   //
   //      return attr.map_state == IsViewable;

   return true;
}


bool window::is_destroying()
{
   if (::is_null(this))
   {
      return true;
   }

   if (m_puserinteractionimpl == nullptr)
   {
      return true;
   }

   if (!m_puserinteractionimpl->m_puserinteraction->m_bUserElementOk)
   {
      return true;
   }

   return false;
}


#undef SET_WINDOW_POS_LOG


//   bool window::set_window_pos(class ::zorder zorder, i32 x, i32 y, i32 cx, i32 cy, ::u32 nFlags)
//   {
//
//      bool bOk = false;
//
//
//                  bOk = _set_window_pos(zorder, x, y, cx, cy, nFlags);
//
//               });
//
//      return bOk;
//
//   }


::e_status window::set_window_icon(const ::file::path& path)
{
   //      Atom net_wm_icon = x11_display()->intern_atom("_BAMF_DESKTOP_FILE", False);
   //
   //      Atom cardinal = x11_display()->intern_atom("STRING", False);
   //
   //      int ixa = XA_STRING;
   //
   //      int status = XChangeProperty(
   //         Display(),
   //         Window(),
   //         net_wm_icon,
   //         ixa,
   //         8,
   //         PropModeReplace,
   //         (const unsigned char *) (const char *) path,
   //         path.length());
   //
   //      informationf("\nfreebsd::interaction_impl::bamf_set_icon END");
   //
   //      fflush(stdout);
   //
   //      if (status != 0)
   //      {
   //
   //         return ::error_failed;
   //
   //      }
   //
   return ::success;
}


//   void oswindow_data::wm_full_screen(const ::rectangle_i32 & rectangle)
//   {
//
//      ::rectangle_i32 rBest;
//
//      int iMonitor = best_xinerama_monitor(m_puserinteractionimpl->m_puserinteraction, rectangle, rBest);
//
//      windowing_output_debug_string("::oswindow_data::full_screen 1");
//
//      xdisplay d(display());
//
//      if(d.is_null())
//      {
//
//         windowing_output_debug_string("::oswindow_data::full_screen 1.1");
//
//         return;
//
//      }
//
//      XWindowAttributes attr;
//
//      if(!XGetWindowAttributes(display(), window(), &attr))
//      {
//
//         windowing_output_debug_string("::oswindow_data::full_screen 1.2");
//
//         fflush(stdout);
//
//         return;
//
//      }
//
//      ::rectangle_i32 rWindow;
//
//      rWindow.left()      = attr.x;
//      rWindow.top()       = attr.y;
//      rWindow.right()     = attr.x    + attr.width;
//      rWindow.bottom()    = attr.y    + attr.height;
//
//      if(rBest != rWindow)
//      {
//
//         m_puserinteractionimpl->m_puserinteraction->place(rBest);
//
//         XMoveResizeWindow(d, m_window, rBest.left(), rBest.top(), rBest.width(), rBest.height());
//
//      }
//
//      if(attr.map_state == IsViewable)
//      {
//
//         mapped_net_state_raw(true, d, window(), m_iScreen, intern_atom(net_wm_state_fullscreen, false), 0);
//
//      }
//      else
//      {
//
//         unmapped_net_state_raw(d, window(), intern_atom(net_wm_state_fullscreen, false), 0);
//
//         XMapWindow(display(), window());
//
//      }
//
//      windowing_output_debug_string("::oswindow_data::full_screen 2");
//
//      ::fflush(stdout);
//
//   }
//


//   ::e_status window::x11_post_message(MESSAGE & msg)
//   {
//
//      try
//      {
//
//         if (msg.oswindow == nullptr)
//         {
//
//            auto pcontext = m_pcontext->m_papexcontext;
//
//            pcontext->post_message(msg.m_atom, msg.wParam, msg.lParam);
//
//         } else
//         {
//
//            if (msg.oswindow != nullptr && msg.oswindow->m_puserinteractionimpl != nullptr &&
//                msg.oswindow->m_puserinteractionimpl->m_puserinteraction != nullptr)
//            {
//
//               ::user::interaction * pinteraction = msg.oswindow->m_puserinteractionimpl->m_puserinteraction;
//
//               pinteraction->post_message(msg.m_atom, msg.wParam, msg.lParam);
//
//            }
//
//         }
//
//      }
//      catch (...)
//      {
//
//      }
//
//      return ::success;
//
//   }
//
//
//   ::e_status window::post_ui_message(const MESSAGE & message)
//   {
//
//      ::oswindow oswindow = message.oswindow;
//
//      ASSERT(oswindow != nullptr);
//
//      ::user::interaction * pinteraction = oswindow->m_puserinteractionimpl->m_puserinteraction;
//
//      ::thread * pthread = nullptr;
//
//      if (::is_set(pinteraction))
//      {
//
//         pthread = pinteraction->m_pthreadUserInteraction;
//
//      }
//
//      if (::is_null(pthread))
//      {
//
//         return ::error_failed;
//
//      }
//
//      auto pmessagequeue = pthread->m_pmessagequeue.get();
//
//      if (pmessagequeue == nullptr)
//      {
//
//         if (message.m_atom == e_message_quit)
//         {
//
//            return ::error_failed;
//
//         }
//
//         pmessagequeue = pthread->aaa_get_message_queue();
//
//      }
//
//      if (pmessagequeue == nullptr)
//      {
//
//         return error_failed;
//
//      }
//
//      synchronous_lock ml(pmessagequeue->synchronization());
//
//      if (message.m_atom == e_message_quit)
//      {
//
//         informationf("e_message_quit thread");
//
//      }
//
//      if (message.m_atom == e_message_left_button_down)
//      {
//
//         informationf("post_ui_message::e_message_left_button_down\n");
//
//      } else if (message.m_atom == e_message_left_button_up)
//      {
//
//         informationf("post_ui_message::e_message_left_button_up\n");
//
//      }
//
//      pmessagequeue->m_messagea.add(message);
//
//      pmessagequeue->m_eventNewMessage.set_event();
//
//      return ::success;
//
//   }
//
//
//   ::e_status window::mq_remove_window_from_all_queues()
//   {
//
//      ::user::interaction * pinteraction = m_puserinteractionimpl->m_puserinteraction;
//
//      if (pinteraction == nullptr)
//      {
//
//         return error_failed;
//
//      }
//
//      if (pinteraction->get_app() == nullptr)
//      {
//
//         return error_failed;
//
//      }
//
//      itask_t idthread = pinteraction->get_app()->get_itask();
//
//      message_queue * pmq = aaa_get_message_queue(idthread, false);
//
//      if (pmq == nullptr)
//      {
//
//         return error_failed;
//
//      }
//
//      synchronous_lock ml(pmq->synchronization());
//
//      pmq->m_messagea.predicate_erase([this](MESSAGE & item)
//                                      {
//
//                                         return item.oswindow == this;
//
//                                      });
//
//      return ::success;
//
//   }


bool window::set_window_position(const class ::zorder& zorder, i32 x, i32 y, i32 cx, i32 cy,
                                 const ::e_activation& eactivation, bool bNoZorder, bool bNoMove, bool bNoSize,
                                 ::e_display edisplay)
{
   synchronous_lock sl(user_synchronization());

   //display_lock displaylock(x11_display()->Display());

   information() << "windowing_gtk4 window::set_window_position ";

   return _set_window_position_unlocked(zorder, x, y, cx, cy, eactivation, bNoZorder, bNoMove, bNoSize,
                                        edisplay);
}


bool window::_set_window_position_unlocked(const class ::zorder& zorder, i32 x, i32 y, i32 cx, i32 cy,
                                           const ::e_activation& eactivation, bool bNoZorder, bool bNoMove,
                                           bool bNoSize, ::e_display edisplay)
{
   windowing_output_debug_string("::window::set_window_pos 1");

   //      XWindowAttributes attrs = {};
   //
   //      if (!XGetWindowAttributes(Display(), Window(), &attrs))
   //      {
   //
   //         windowing_output_debug_string("::window::set_window_pos 1.1 xgetwindowattr failed");
   //
   //         return false;
   //
   //      }
   //
   //      if (windowing()->is_screen_visible(edisplay))
   //      {
   //
   //         if (attrs.map_state == IsUnmapped)
   //         {
   //
   //            windowing_output_debug_string("::window::set_window_pos Mapping Window 1.2");
   //
   //            XMapWindow(Display(), Window());
   //
   //         }
   //
   //         if (!XGetWindowAttributes(Display(), Window(), &attrs))
   //         {
   //
   //            windowing_output_debug_string("::window::set_window_pos 1.3 xgetwindowattr failed");
   //
   //            return false;
   //
   //         }
   //
   //      }
   //
   //      bool bMove = !bNoMove;
   //
   //      bool bSize = !bNoSize;
   //
   //      if (bMove)
   //      {
   //
   //         if (bSize)
   //         {
   //
   //            windowing_output_debug_string("::window::set_window_pos Move Resize Window 1.4");
   //
   //#ifdef SET_WINDOW_POS_LOG
   //
   //            informationf("XMoveResizeWindow (%Display(), %d) - (%Display(), %d)", x, y, cx, cy);
   //
   //#endif
   //
   //            if (cx <= 0 || cy <= 0)
   //            {
   //
   //               cx = 1;
   //
   //               cy = 1;
   //
   //#ifdef SET_WINDOW_POS_LOG
   //
   //               informationf("Changing parameters... (%d, %d) - (%d, %d)", x, y, cx, cy);
   //
   //#endif
   //
   //            }
   //
   ////            if (x < 100 || y < 100)
   ////            {
   ////
   ////               informationf("XMoveResizeWindow x or y less than 100 ... (Win=%d) (%d, %d) - (%d, %d)", Window(), x, y, cx, cy);
   ////
   ////            }
   //
   //            //informationf("XMoveResizeWindow (Win=%d) (%d, %d) - (%d, %d) - (%d, %d)", Window(), x, y, cx, cy, x + cx, y + cy);
   //
   //            //information() << node()->get_callstack();
   //
   //            XMoveResizeWindow(Display(), Window(), x, y, cx, cy);
   //
   //
   ////            if(m_puserinteractionimpl->m_puserinteraction->const_layout().design().display() == e_display_zoomed) {
   ////
   ////               x11_windowing()->_defer_position_and_size_message(m_oswindow);
   ////
   ////
   ////            }
   //
   //
   //         } else
   //         {
   //
   //            if (x < 100 || y < 100)
   //            {
   //
   //               informationf("XMoveWindow x or y less than 100 ... (Win=%d) (%d, %d) - (%d, %d)", Window(), x, y, cx, cy);
   //
   //            }
   //
   //            windowing_output_debug_string("::window::set_window_pos Move Window 1.4.1");
   //
   //            XMoveWindow(Display(), Window(), x, y);
   //
   //         }
   //
   //      } else if (bSize)
   //      {
   //
   //         windowing_output_debug_string("::window::set_window_pos Resize Window 1.4.2");
   //
   //         XResizeWindow(Display(), Window(), cx, cy);
   //
   //      }
   //
   //      //   if(bMove || bSize)
   //      //   {
   //      //
   //      //      if(attrs.override_redirect)
   //      //      {
   //      //
   //      //         if(!(m_puserinteractionimpl->m_puserinteraction->m_ewindowflag & e_window_flag_arbitrary_positioning))
   //      //         {
   //      //
   //      //            XSetWindowAttributes set;
   //      //
   //      //            set.override_redirect = False;
   //      //
   //      //            if(!XChangeWindowAttributes(Display(), Window(), CWOverrideRedirect, &set))
   //      //            {
   //      //
   //      //               information() << "freebsd::interaction_impl::_native_create_window_ex failed to clear override_redirect";
   //      //
   //      //            }
   //      //
   //      //         }
   //      //
   //      //      }
   //      //
   //      //   }
   //
   //
   //      if (!windowing()->is_screen_visible(edisplay))
   //      {
   //
   //         if (attrs.map_state == IsViewable)
   //         {
   //
   //            windowing_output_debug_string("::window::set_window_pos Withdraw Window 1.4.3");
   //
   //            XWithdrawWindow(Display(), Window(), Screen());
   //
   //         }
   //
   //      }
   //
   //      if (XGetWindowAttributes(Display(), Window(), &attrs) == 0)
   //      {
   //
   //         windowing_output_debug_string("::window::set_window_pos xgetwndattr 1.4.4");
   //
   //         return false;
   //
   //      }
   //
   //      if (attrs.map_state == IsViewable || windowing()->is_screen_visible(edisplay))
   //      {
   //
   //         if (!bNoZorder)
   //         {
   //
   //            if (zorder.m_ezorder == e_zorder_top_most)
   //            {
   //
   //               if (net_wm_state(::x11::e_atom_net_wm_state_above) != 1)
   //               {
   //
   //                  _wm_state_above_unlocked(true);
   //
   //               }
   //
   //               XRaiseWindow(Display(), Window());
   //
   //            } else if (zorder.m_ezorder == e_zorder_top)
   //            {
   //
   //               if (net_wm_state(::x11::e_atom_net_wm_state_above) != 0
   //                   || net_wm_state(::x11::e_atom_net_wm_state_below) != 0
   //                   || net_wm_state(::x11::e_atom_net_wm_state_hidden) != 0
   //                   || net_wm_state(::x11::e_atom_net_wm_state_maximized_horz) != 0
   //                   || net_wm_state(::x11::e_atom_net_wm_state_maximized_penn) != 0
   //                   || net_wm_state(::x11::e_atom_net_wm_state_fullscreen) != 0)
   //               {
   //
   //                  _wm_state_clear_unlocked(false);
   //
   //               }
   //
   //               XRaiseWindow(Display(), Window());
   //
   //            } else if (zorder.m_ezorder == e_zorder_bottom)
   //            {
   //
   //               if (net_wm_state(::x11::e_atom_net_wm_state_below) != 1)
   //               {
   //
   //                  _wm_state_below_unlocked(true);
   //
   //               }
   //
   //               XLowerWindow(Display(), Window());
   //
   //            }
   //
   //         }
   //
   //         //m_puserinteractionimpl->m_puserinteraction->ModifyStyle(0, WS_VISIBLE, 0);
   //
   //      }
   ////      else
   ////      {
   ////
   ////         //m_puserinteractionimpl->m_puserinteraction->ModifyStyle(WS_VISIBLE, 0, 0);
   ////
   ////      }
   //
   //      //m_puserinteractionimpl->on_change_visibility();


   windowing_output_debug_string("::window::set_window_pos 2");

   return true;
}


//   bool window::_set_window_position_unlocked(const class ::zorder & zorder, i32 x, i32 y, i32 cx, i32 cy,
//                                              const ::e_activation & eactivation, bool bNoZorder, bool bNoMove,
//                                              bool bNoSize, bool bShow, bool bHide)
//   {
//
//      windowing_output_debug_string("::window::set_window_pos 1");
//
//      XWindowAttributes attrs = {};
//
//      if (!XGetWindowAttributes(Display(), Window(), &attrs))
//      {
//
//         windowing_output_debug_string("::window::set_window_pos 1.1 xgetwindowattr failed");
//
//         return false;
//
//      }
//
//      if (bShow)
//      {
//
//         if (attrs.map_state == IsUnmapped)
//         {
//
//            windowing_output_debug_string("::window::set_window_pos Mapping Window 1.2");
//
//            XMapWindow(Display(), Window());
//
//         }
//
//         if (!XGetWindowAttributes(Display(), Window(), &attrs))
//         {
//
//            windowing_output_debug_string("::window::set_window_pos 1.3 xgetwindowattr failed");
//
//            return false;
//
//         }
//
//      }
//
//      bool bMove = !bNoMove;
//
//      bool bSize = !bNoSize;
//
//      if (bMove)
//      {
//
//         if (bSize)
//         {
//
//            windowing_output_debug_string("::window::set_window_pos Move Resize Window 1.4");
//
//#ifdef SET_WINDOW_POS_LOG
//
//            informationf("XMoveResizeWindow (%Display(), %d) - (%Display(), %d)", x, y, cx, cy);
//
//#endif
//
//            if (cx <= 0 || cy <= 0)
//            {
//
//               cx = 1;
//
//               cy = 1;
//
//#ifdef SET_WINDOW_POS_LOG
//
//               informationf("Changing parameters... (%d, %d) - (%d, %d)", x, y, cx, cy);
//
//#endif
//
//            }
//
////            if (x < 100 || y < 100)
////            {
////
////               informationf("XMoveResizeWindow x or y less than 100 ... (Win=%d) (%d, %d) - (%d, %d)", Window(), x, y, cx, cy);
////
////            }
//
//            //informationf("XMoveResizeWindow (Win=%d) (%d, %d) - (%d, %d) - (%d, %d)", Window(), x, y, cx, cy, x + cx, y + cy);
//
//            //information() << node()->get_callstack();
//
//            XMoveResizeWindow(Display(), Window(), x, y, cx, cy);
//
//
////            if(m_puserinteractionimpl->m_puserinteraction->const_layout().design().display() == e_display_zoomed) {
////
////               x11_windowing()->_defer_position_and_size_message(m_oswindow);
////
////
////            }
//
//
//         } else
//         {
//
//            if (x < 100 || y < 100)
//            {
//
//               informationf("XMoveWindow x or y less than 100 ... (Win=%d) (%d, %d) - (%d, %d)", Window(), x, y, cx, cy);
//
//            }
//
//            windowing_output_debug_string("::window::set_window_pos Move Window 1.4.1");
//
//            XMoveWindow(Display(), Window(), x, y);
//
//         }
//
//      } else if (bSize)
//      {
//
//         windowing_output_debug_string("::window::set_window_pos Resize Window 1.4.2");
//
//         XResizeWindow(Display(), Window(), cx, cy);
//
//      }
//
//      //   if(bMove || bSize)
//      //   {
//      //
//      //      if(attrs.override_redirect)
//      //      {
//      //
//      //         if(!(m_puserinteractionimpl->m_puserinteraction->m_ewindowflag & e_window_flag_arbitrary_positioning))
//      //         {
//      //
//      //            XSetWindowAttributes set;
//      //
//      //            set.override_redirect = False;
//      //
//      //            if(!XChangeWindowAttributes(Display(), Window(), CWOverrideRedirect, &set))
//      //            {
//      //
//      //               information() << "freebsd::interaction_impl::_native_create_window_ex failed to clear override_redirect";
//      //
//      //            }
//      //
//      //         }
//      //
//      //      }
//      //
//      //   }
//
//
//      if (bHide)
//      {
//
//         if (attrs.map_state == IsViewable)
//         {
//
//            windowing_output_debug_string("::window::set_window_pos Withdraw Window 1.4.3");
//
//            XWithdrawWindow(Display(), Window(), Screen());
//
//         }
//
//      }
//
//      if (XGetWindowAttributes(Display(), Window(), &attrs) == 0)
//      {
//
//         windowing_output_debug_string("::window::set_window_pos xgetwndattr 1.4.4");
//
//         return false;
//
//      }
//
//      if (attrs.map_state == IsViewable || bShow)
//      {
//
//         if (!bNoZorder)
//         {
//
//            if (zorder.m_ezorder == e_zorder_top_most)
//            {
//
//               if (net_wm_state(::x11::e_atom_net_wm_state_above) != 1)
//               {
//
//                  _wm_state_above_unlocked(true);
//
//               }
//
//               XRaiseWindow(Display(), Window());
//
//            } else if (zorder.m_ezorder == e_zorder_top)
//            {
//
//               if (net_wm_state(::x11::e_atom_net_wm_state_above) != 0
//                   || net_wm_state(::x11::e_atom_net_wm_state_below) != 0
//                   || net_wm_state(::x11::e_atom_net_wm_state_hidden) != 0
//                   || net_wm_state(::x11::e_atom_net_wm_state_maximized_horz) != 0
//                   || net_wm_state(::x11::e_atom_net_wm_state_maximized_penn) != 0
//                   || net_wm_state(::x11::e_atom_net_wm_state_fullscreen) != 0)
//               {
//
//                  _wm_state_clear_unlocked(false);
//
//               }
//
//               XRaiseWindow(Display(), Window());
//
//            } else if (zorder.m_ezorder == e_zorder_bottom)
//            {
//
//               if (net_wm_state(::x11::e_atom_net_wm_state_below) != 1)
//               {
//
//                  _wm_state_below_unlocked(true);
//
//               }
//
//               XLowerWindow(Display(), Window());
//
//            }
//
//         }
//
//         //m_puserinteractionimpl->m_puserinteraction->ModifyStyle(0, WS_VISIBLE, 0);
//
//      }
////      else
////      {
////
////         //m_puserinteractionimpl->m_puserinteraction->ModifyStyle(WS_VISIBLE, 0, 0);
////
////      }
//
//      //m_puserinteractionimpl->on_change_visibility();
//
//      windowing_output_debug_string("::window::set_window_pos 2");
//
//      return true;
//
//   }


bool window::_configure_window_unlocked(const class ::zorder& zorder,
                                        const ::e_activation& eactivation, bool bNoZorder, ::e_display edisplay)
{
   if (!(m_puserinteractionimpl->m_puserinteraction->m_ewindowflag & e_window_flag_window_created))
   {
      return false;
   }

   //       if (m_uLastRequestSerial == m_uLastConfigureSerial)
   //       {
   //
   //          return false;
   //
   //       }
   //
   //       if (::is_null(m_pxdgtoplevel))
   //       {
   //
   //          return false;
   //
   //       }
   //
   // //      node()->post_procedure([this, zorder, eactivation, bNoZorder, edisplay]()
   // //                                 {
   //
   // //                                    if(m_uLastRequestSerial == m_uLastConfigureSerial)
   // //                                    {
   // //
   // //                                       return;
   // //
   // //                                    }
   //
   //
   //       windowing_output_debug_string("::window::_configure_window_unlocked 1");

   //      m_atomaNetWmState = _get_net_wm_state_unlocked();
   //
   //      if (windowing()->is_screen_visible(edisplay))
   //      {
   //
   //         if (m_xwindowattributes.map_state == IsUnmapped)
   //         {
   //
   //            information() << "_configure_window_unlocked XMapWindow";
   //
   //            windowing_output_debug_string("::window::set_window_pos Mapping Window 1.2");
   //
   //            XMapWindow(Display(), Window());
   //
   //            if (!XGetWindowAttributes(Display(), Window(), &m_xwindowattributes))
   //            {
   //
   //               windowing_output_debug_string("::window::set_window_pos 1.3 xgetwindowattr failed");
   //
   //               return false;
   //
   //            }
   //
   //         }
   //
   //      }
   //

   //       if (m_pxdgtoplevel)
   //       {
   //          if (edisplay != e_display_zoomed &&
   //              m_puserinteractionimpl->m_puserinteraction->const_layout().window().display() == e_display_zoomed)
   //          {
   //
   //             information() << "xdg_toplevel_unset_maximized";
   //
   //             m_uLastRequestSerial = m_uLastConfigureSerial;
   //
   //             m_timeLastConfigureRequest.Now();
   //
   //             xdg_toplevel_unset_maximized(m_pxdgtoplevel);
   //
   //          }
   //       }
   //
   //
   // //         auto atomMaxH = x11_display()->m_atomNetWmStateMaximizedHorz;
   // //
   // //         auto atomMaxP = x11_display()->m_atomNetWmStateMaximizedVert;
   // //
   // //         for(auto & a : m_atomaNetWmState)
   // //         {
   // //
   // //            informationf("atom_name: %s", XGetAtomName(Display(), a));
   // //
   // //         }
   // //
   // //         if(m_atomaNetWmState.contains(atomMaxH) || m_atomaNetWmState.contains(atomMaxP))
   // //         {
   // //
   // //            information() << "_configure_window_unlocked Clearing Maximized States";
   // //
   // //            _wm_state_clear_unlocked(false);
   // //
   // //         }
   // //
   // //      }
   // //
   //
   //       if (edisplay == e_display_iconic)
   //       {
   //
   //          if (m_pxdgtoplevel)
   //          {
   //
   //             information() << "xdg_toplevel_set_minimized";
   //
   // //         XIconifyWindow(Display(), Window(), Screen());
   // //         if (edisplay == e_display_iconic)
   // //         {
   //
   //             m_uLastRequestSerial = m_uLastConfigureSerial;
   //
   //             m_timeLastConfigureRequest.Now();
   //
   //
   //             //wm_iconify_window();
   //             xdg_toplevel_set_minimized(m_pxdgtoplevel);
   //
   //             //wl_surface_commit(m_pwlsurface);
   //
   //
   // //         m_timeLastConfigureRequest.Now();
   //
   // //         }
   //
   //             //return true;
   //          }
   //
   //       }
   //       else if (edisplay == e_display_zoomed)
   //       {
   //
   //          if (m_pxdgtoplevel)
   //          {
   //
   //             information() << "xdg_toplevel_set_maximized";
   //
   //             m_uLastRequestSerial = m_uLastConfigureSerial;
   //
   //             m_timeLastConfigureRequest.Now();
   //
   //             xdg_toplevel_set_maximized(m_pxdgtoplevel);
   //
   //             //wl_surface_commit(m_pwlsurface);
   // //         m_timeLastConfigureRequest.Now();
   //
   //             //wl_display_dispatch(wayland_display()->m_pwldisplay);
   //
   //             //wl_display_roundtrip(wayland_display()->m_pwldisplay);
   //
   // //
   // //         auto atomMaxH = x11_display()->m_atomNetWmStateMaximizedHorz;
   // //
   // //         auto atomMaxP = x11_display()->m_atomNetWmStateMaximizedVert;
   // //
   // //         if (!m_atomaNetWmState.contains(atomMaxH) || !m_atomaNetWmState.contains(atomMaxP))
   // //         {
   // //
   // //            information() << "_configure_window_unlocked Setting Maximized States";
   // //
   // //            _mapped_net_state_unlocked(true, x11_display()->m_iScreen, atomMaxH, atomMaxP);
   // //
   // ////            comparable_array<Atom> atoma;
   // ////
   // ////            auto atomList = x11_display()->m_atomNetWmState;
   // ////
   // ////            if (atomList != None)
   // ////            {
   // ////
   // ////               Atom actual_type;
   // ////
   // ////               int actual_format;
   // ////
   // ////               unsigned long int bytes_after;
   // ////
   // ////               Atom * patoms = nullptr;
   // ////
   // ////               long unsigned int num_items = 0;
   // ////
   // ////               XGetWindowProperty(Display(), Window(), atomList, 0, 1024,
   // ////                                  False, XA_ATOM, &actual_type, &actual_format,
   // ////                                  &num_items,
   // ////                                  &bytes_after, (unsigned char **) &patoms);
   // ////
   // ////               atoma.set_size(num_items);
   // ////
   // ////               memory_copy(atoma.data(), patoms, atoma.get_size_in_bytes());
   // ////
   // ////               XFree(patoms);
   // ////
   // ////
   // ////            }
   // //
   // //
   // //         }
   //
   //
   // //
   //
   //          }
   //       }
   //       else if (!windowing()->is_screen_visible(edisplay))
   //       {
   //
   //          if (m_pxdgtoplevel)
   //          {
   //
   //             xdg_toplevel_destroy(m_pxdgtoplevel);
   //
   //             m_pxdgtoplevel = nullptr;
   //
   //          }
   //
   //       }
   // //
   // //         if (m_xwindowattributes.map_state == IsViewable)
   // //         {
   // //
   // //            information() << "_configure_window_unlocked XWithdrawWindow";
   // //
   // //            windowing_output_debug_string("::window::set_window_pos Withdraw Window 1.4.3");
   // //
   // //            XWithdrawWindow(Display(), Window(), Screen());
   // //
   // //            if (XGetWindowAttributes(Display(), Window(), &m_xwindowattributes) == 0)
   // //            {
   // //
   // //               windowing_output_debug_string("::window::set_window_pos xgetwndattr 1.4.4");
   // //
   // //               return false;
   // //
   // //            }
   // //
   // //         }
   // //
   // //      }
   // //
   // //      if (m_xwindowattributes.map_state == IsViewable || windowing()->is_screen_visible(edisplay))
   // //      {
   // //
   //
   //       if (!bNoZorder)
   //       {
   //
   //          if (zorder.m_ezorder == e_zorder_top_most)
   //          {
   //
   // //               if (net_wm_state(::x11::e_atom_net_wm_state_above) != 1)
   // //               {
   // //
   // //                  _wm_state_above_unlocked(true);
   // //
   // //               }
   //
   //             //             XRaiseWindow(Display(), Window());
   //
   //             information() << "::windowing_gtk4::window::_configure_window_unlocked e_zorder_top_most";
   //
   //             __activate_window(true);
   //
   //          }
   //          else if (zorder.m_ezorder == e_zorder_top)
   //          {
   //
   // //               if (net_wm_state(::x11::e_atom_net_wm_state_above) != 0
   // //                   || net_wm_state(::x11::e_atom_net_wm_state_below) != 0
   // //                   || net_wm_state(::x11::e_atom_net_wm_state_hidden) != 0
   // //                   || net_wm_state(::x11::e_atom_net_wm_state_maximized_horz) != 0
   // //                   || net_wm_state(::x11::e_atom_net_wm_state_maximized_penn) != 0
   // //                   || net_wm_state(::x11::e_atom_net_wm_state_fullscreen) != 0)
   // //               {
   // //
   // //                  _wm_state_clear_unlocked(false);
   // //
   // //               }
   // //
   // //               XRaiseWindow(Display(), Window());
   //
   //             information() << "::windowing_gtk4::window::_configure_window_unlocked e_zorder_top";
   //
   //             __activate_window(true);
   //
   //          }
   //          else if (zorder.m_ezorder == e_zorder_bottom)
   //          {
   //
   // //               if (net_wm_state(::x11::e_atom_net_wm_state_below) != 1)
   // //               {
   // //
   // //                  _wm_state_below_unlocked(true);
   // //
   // //               }
   // //
   // //               XLowerWindow(Display(), Window());
   //
   //          }
   //
   //       }
   //       else if (eactivation != e_activation_default)
   //       {
   //
   //          information() << "::windowing_gtk4::window::_configure_window_unlocked eactivation : "
   //                        << (::iptr) eactivation;
   //
   //          __activate_window(true);
   //
   //       }
   //
   // //         if (!bNoZorder)
   // //         {
   // //
   // //            if (zorder.m_ezorder == e_zorder_top_most)
   // //            {
   // //
   // //               if (net_wm_state(::x11::e_atom_net_wm_state_above) != 1)
   // //               {
   // //
   // //                  _wm_state_above_unlocked(true);
   // //
   // //               }
   // //
   // //               information() << "_configure_window_unlocked XRaiseWindow";
   // //
   // //               XRaiseWindow(Display(), Window());
   // //
   // //            }
   // //            else if (zorder.m_ezorder == e_zorder_top)
   // //            {
   // //
   // //               if (net_wm_state(::x11::e_atom_net_wm_state_above) != 0
   // //                   || net_wm_state(::x11::e_atom_net_wm_state_below) != 0
   // //                   || net_wm_state(::x11::e_atom_net_wm_state_hidden) != 0
   // //                   || net_wm_state(::x11::e_atom_net_wm_state_maximized_horz) != 0
   // //                   || net_wm_state(::x11::e_atom_net_wm_state_maximized_penn) != 0
   // //                   || net_wm_state(::x11::e_atom_net_wm_state_fullscreen) != 0)
   // //               {
   // //
   // //                  _wm_state_clear_unlocked(false);
   // //
   // //               }
   // //
   // //               information() << "_configure_window_unlocked XRaiseWindow";
   // //
   // //               XRaiseWindow(Display(), Window());
   // //
   // //            }
   // //            else if (zorder.m_ezorder == e_zorder_bottom)
   // //            {
   // //
   // //               if (net_wm_state(::x11::e_atom_net_wm_state_below) != 1)
   // //               {
   // //
   // //                  _wm_state_below_unlocked(true);
   // //
   // //               }
   // //
   // //               information() << "_configure_window_unlocked XLowerWindow";
   // //
   // //               XLowerWindow(Display(), Window());
   // //
   // //            }
   // //
   // //         }
   // //
   // //      }
   //
   //       windowing_output_debug_string("::window::set_window_pos 2");
   // //                                    ::pointer < ::windowing_gtk4::display > pwaylanddisplay = m_pnanouserdisplay;
   //       //                                  wl_display_flush(pwaylanddisplay->m_pwldisplay);
   //
   //       //wl_surface_commit(m_pwlsurface);
   //
   // //                                    node()->post_procedure([this]()
   // //                                                               {
   // //                                                                  ::pointer < ::windowing_gtk4::display > pwaylanddisplay = m_pnanouserdisplay;
   // //                                                                  wl_display_flush(pwaylanddisplay->m_pwldisplay);
   // ////
   // ////      ::pointer < ::windowing_gtk4::display > pwaylanddisplay = m_pnanouserdisplay;
   // ////      wl_display_dispatch(pwaylanddisplay->m_pwldisplay);
   // ////
   // ////      wl_display_roundtrip(pwaylanddisplay->m_pwldisplay);
   // ////
   // //                                                               });
   //
   // //                                 });
   //
   return true;
}


bool window::_strict_set_window_position_unlocked(i32 x, i32 y, i32 cx, i32 cy, bool bNoMove, bool bNoSize)
{
   bool bMove = !bNoMove;

   bool bSize = !bNoSize;

   if (bMove)
   {
      if (bSize)
      {
         windowing_output_debug_string("::window::set_window_pos Move Resize Window 1.4");

#ifdef SET_WINDOW_POS_LOG

            informationf("XMoveResizeWindow (%Display(), %d) - (%Display(), %d)", x, y, cx, cy);

#endif

         if (cx <= 0 || cy <= 0)
         {
            cx = 1;

            cy = 1;

#ifdef SET_WINDOW_POS_LOG

            //informationf("Changing parameters... (%d, %d) - (%d, %d)", x, y, cx, cy);

#endif
         }

         //            if (x < 100 || y < 100)
         //            {
         //
         //               informationf("XMoveResizeWindow x or y less than 100 ... (Win=%d) (%d, %d) - (%d, %d)", Window(), x, y, cx, cy);
         //
         //            }

         //informationf("XMoveResizeWindow (Win=%d) (%d, %d) - (%d, %d) - (%d, %d)", Window(), x, y, cx, cy, x + cx, y + cy);

         //information() << node()->get_callstack();

         //            XMoveResizeWindow(Display(), Window(), x, y, cx, cy);


         //            if(m_puserinteractionimpl->m_puserinteraction->const_layout().design().display() == e_display_zoomed) {
         //
         //               x11_windowing()->_defer_position_and_size_message(m_oswindow);
         //
         //
         //            }
      }
      else
      {
         if (x < 100 || y < 100)
         {
            //informationf("XMoveWindow x or y less than 100 ... (Win=%d) (%d, %d) - (%d, %d)", Window(), x, y, cx, cy);
         }

         windowing_output_debug_string("::window::set_window_pos Move Window 1.4.1");

         //informationf("XMoveWindow (Win=%d) (%d, %d)", Window(), x, y);

         //XMoveWindow(Display(), Window(), x, y);
      }
   }
   else if (bSize)
   {
      windowing_output_debug_string("::window::set_window_pos Resize Window 1.4.2");

      //informationf("XResizeWindow (Win=%d) (%d, %d)", Window(), cx, cy);

      //information() << node()->get_callstack();

      //XResizeWindow(Display(), Window(), cx, cy);
   }

   //   if(bMove || bSize)
   //   {
   //
   //      if(attrs.override_redirect)
   //      {
   //
   //         if(!(m_puserinteractionimpl->m_puserinteraction->m_ewindowflag & e_window_flag_arbitrary_positioning))
   //         {
   //
   //            XSetWindowAttributes set;
   //
   //            set.override_redirect = False;
   //
   //            if(!XChangeWindowAttributes(Display(), Window(), CWOverrideRedirect, &set))
   //            {
   //
   //               information() << "freebsd::interaction_impl::_native_create_window_ex failed to clear override_redirect";
   //
   //            }
   //
   //         }
   //
   //      }
   //
   //   }


   //      if (bHide)
   //      {
   //
   //         if (attrs.map_state == IsViewable)
   //         {
   //
   //            windowing_output_debug_string("::window::set_window_pos Withdraw Window 1.4.3");
   //
   //            XWithdrawWindow(Display(), Window(), Screen());
   //
   //         }
   //
   //      }
   //
   //      if (XGetWindowAttributes(Display(), Window(), &attrs) == 0)
   //      {
   //
   //         windowing_output_debug_string("::window::set_window_pos xgetwndattr 1.4.4");
   //
   //         return false;
   //
   //      }
   //
   //      if (attrs.map_state == IsViewable || bShow)
   //      {
   //
   //         if (!bNoZorder)
   //         {
   //
   //            if (zorder.m_ezorder == e_zorder_top_most)
   //            {
   //
   ////               if (net_wm_state(::x11::e_atom_net_wm_state_above) != 1)
   ////               {
   ////
   ////                  _wm_state_above_unlocked(true);
   ////
   ////               }
   //
   //  //             XRaiseWindow(Display(), Window());
   //
   //               __activate_window(false);
   //
   //            } else if (zorder.m_ezorder == e_zorder_top)
   //            {
   //
   ////               if (net_wm_state(::x11::e_atom_net_wm_state_above) != 0
   ////                   || net_wm_state(::x11::e_atom_net_wm_state_below) != 0
   ////                   || net_wm_state(::x11::e_atom_net_wm_state_hidden) != 0
   ////                   || net_wm_state(::x11::e_atom_net_wm_state_maximized_horz) != 0
   ////                   || net_wm_state(::x11::e_atom_net_wm_state_maximized_penn) != 0
   ////                   || net_wm_state(::x11::e_atom_net_wm_state_fullscreen) != 0)
   ////               {
   ////
   ////                  _wm_state_clear_unlocked(false);
   ////
   ////               }
   ////
   ////               XRaiseWindow(Display(), Window());
   //               __activate_window(false);
   //
   //            } else if (zorder.m_ezorder == e_zorder_bottom)
   //            {
   //
   ////               if (net_wm_state(::x11::e_atom_net_wm_state_below) != 1)
   ////               {
   ////
   ////                  _wm_state_below_unlocked(true);
   ////
   ////               }
   ////
   ////               XLowerWindow(Display(), Window());
   //
   //            }
   //
   //         }
   //         else if(eactivation != e_activation_default)
   //         {
   //
   //            __activate_window(false);
   //
   //         }
   //
   //         //m_puserinteractionimpl->m_puserinteraction->ModifyStyle(0, WS_VISIBLE, 0);
   //
   //      }
   ////      else
   ////      {
   ////
   ////         //m_puserinteractionimpl->m_puserinteraction->ModifyStyle(WS_VISIBLE, 0, 0);
   ////
   ////      }
   //
   //      //m_puserinteractionimpl->on_change_visibility();

   // windowing_output_debug_string("::window::_strict_set_window_position_unlocked 2");
   //
   // if (bMove || bSize)
   // {
   //
   //    if (bMove)
   //    {
   //
   //       m_pointWindow.x() = x;
   //       m_pointWindow.y() = y;
   //
   //    }
   //
   //    if (bSize)
   //    {
   //
   //       m_sizeWindow.cx() = cx;
   //       m_sizeWindow.cy() = cy;
   //
   //    }
   //
   //    auto frame = m_puserinteractionimpl->m_puserinteraction->outer_frame();
   //
   //    information() << "xdg_surface_set_window_geometry : " << frame;
   //
   //    //m_uLastRequestSerial = m_uLastConfigureSerial;
   //
   //    //m_timeLastConfigureRequest.Now();
   //
   //    xdg_surface_set_window_geometry(
   //       m_pxdgsurface,
   //       frame.left(), frame.top(),
   //       frame.width(), frame.height());
   //
   //    if (m_pwlsubsurface)
   //    {
   //
   //       wl_subsurface_set_position(
   //          m_pwlsubsurface,
   //          m_pointWindow.x(), m_pointWindow.y());
   //
   //    }
   //
   // }

   return true;
}


//   int_bool window::show_window(
//                        const ::e_display &edisplay,
//                        const ::e_activation &eactivation
//   )
//   {
//
//      x11_sync([oswindow, edisplay, eactivation]()
//               {
//
//                  return oswindow->
//                     show_window(edisplay, eactivation
//                  );
//
//               });
//
//      return true;
//
//   }


//   iptr get_window_long_ptr(window *pdata, int
//   nIndex)
//   {
//
//      return pdata->
//         get_window_long_ptr(nIndex);
//
//   }


//   iptr set_window_long_ptr(window *pdata, int
//   nIndex,
//                            iptr i
//   )
//   {
//
//      return pdata->
//         set_window_long_ptr(nIndex, i
//      );
//
//   }


void window::set_window_text(const ::scoped_string& scopedstr)
{
   //      m_strWindowText = pszString;

   //windowing_output_debug_string("\nfreebsd::interaction_impl::set_window_text");

   //fflush(stdout);

   //x11_store_name(m_oswindow, m_strWindowText);

   //x11_store_name(scopedstr);

   //windowing_output_debug_string("\nfreebsd::interaction_impl::set_window_text END");

   //fflush(stdout);
}


void window::set_tool_window(bool bSet)
{
   //wm_toolwindow(bSet);

   //return ::success;
}


void window::set_mouse_cursor2(::windowing::cursor* pcursor)
{
   synchronous_lock synchronouslock(user_synchronization());

   //      display_lock displaylock(x11_display()->Display());
   //
   //      Atom net_wm_icon = x11_display()->intern_atom("_BAMF_DESKTOP_FILE", False);
   //
   //      Atom cardinal = x11_display()->intern_atom("STRING", False);
   //
   //      int ixa = XA_STRING;
   //
   //      ::file::path path = pcursor->get_file_path();
   //
   //      int status = XChangeProperty(
   //         Display(),
   //         Window(),
   //         net_wm_icon,
   //         ixa,
   //         8,
   //         PropModeReplace,
   //         (const unsigned char *) (const char *) path,
   //         path.length());
   //
   //      informationf("\nfreebsd::interaction_impl::bamf_set_icon END");
   //
   //      fflush(stdout);
   //
   //      if (status != 0)
   //      {
   //
   //         throw ::exception(error_failed);
   //
   //      }


   //return true;
}


void window::set_mouse_cursor(::windowing::cursor* pcursor)
{
   ::windowing::window::set_mouse_cursor(pcursor);

   windowing()->set_mouse_cursor2(pcursor);
}


//   string window::x11_get_name()
//   {
//
//      return ::x11_get_name(Display(), Window());
//
//   }
//
//
//   bool window::x11_get_window_rect(::rectangle_i32 * prectangle)
//   {
//
//      return ::x11_get_window_rect(Display(), Window(), prectangle);
//
//   }


::e_status window::window_rectangle(::rectangle_i32* prectangle)
{
   //return x11_get_window_rect(prectangle) ? ::success : ::error_failed;

   return ::success;
}


//   bool window::x11_get_client_rect(::rectangle_i32 * prectangle)
//   {
//
//      //return ::x11_get_client_rect(Display(), Window(), prectangle);
//
//      return ::success;
//
//   }


::e_status window::rectangle(::rectangle_i32* prectangle)
{
   //return x11_get_client_rect(prectangle) ? ::success : error_failed;
   return ::success;
}


//   void window::upper_window_rects(rectangle_i32_array & ra)
//   {
//
//      synchronous_lock synchronouslock(user_synchronization());
//
////      ra.erase_all();
////
////      windowing_output_debug_string("::GetFocus 1");
////
////#ifdef display_lock_LOCK_LOG
////
////      b_prevent_display_lock_lock_log = false;
////
////#endif
////
////      display_lock displaylock(x11_display()->Display());
////
////      windowing_output_debug_string("::GetFocus 1.01");
////
////      auto windowa = x11_display()->x11_window_list();
////
////      if (windowa.last() == Window())
////      {
////
////         return;
////
////      }
////
////      auto iFind = windowa.find_last(Window());
////
////      if (not_found(iFind))
////      {
////
////         return;
////
////      }
////
////      ::rectangle_i32 rectangle;
////
////      x11_get_window_rect(&rectangle);
////
//////r = oswindow->m_puserinteractionimpl->m_puserinteraction->window_rectangle();
////
//////string strTopic = x11_get_name(x11_display(), Window());
////
////      ::rectangle_i32 rectangleTest;
////
////      for (iFind++; iFind < windowa.get_size(); iFind++)
////      {
////
//////string strItem = x11_get_name(x11_display(), windowa[iFind]);
////
////         ::rectangle_i32 rectangleHigher;
////
////         if (::x11_get_window_rect(Display(), windowa[iFind], &rectangleHigher))
////         {
////
////            ra.add(rectangleHigher);
////
////         }
////
////      }
//
//   }


void window::set_active_window()
{
   synchronous_lock synchronouslock(user_synchronization());

   information() << "::windowing_gtk4::window::set_active_window";

   user_post([this]()
   {
      windowing_output_debug_string("::set_active_window 1");

      //         display_lock displaylock(x11_display()->Display());

      _set_active_window_unlocked();

      //         XEvent xev;
      //
      //         zero(xev);
      //
      //         auto windowRoot = DefaultRootWindow(Display());
      //
      //         Atom atomActiveWindow = x11_display()->intern_atom("_NET_ACTIVE_WINDOW", False);
      //
      //         xev.xclient.type = ClientMessage;
      //         xev.xclient.send_event = True;
      //         xev.xclient.display = Display();
      //         xev.xclient.window = Window();
      //         xev.xclient.message_type = atomActiveWindow;
      //         xev.xclient.format = 32;
      //         xev.xclient.data.l[0] = 1;
      //         xev.xclient.data.l[1] = 0;
      //         xev.xclient.data.l[2] = 0;
      //         xev.xclient.data.l[3] = 0;
      //         xev.xclient.data.l[4] = 0;
      //
      //         XSendEvent(Display(), windowRoot, False, SubstructureRedirectMask | SubstructureNotifyMask, &xev);
      //
      //         windowing_output_debug_string("::set_active_window 2");
   });

   //      //auto estatus =
   //      //
   //      set_keyboard_focus();
   //
   ////      if (!estatus)
   ////      {
   ////
   ////         return estatus;
   ////
   ////      }
   ////
   ////      return estatus;
}


void window::_set_active_window_unlocked()
{
   if (!(m_puserinteractionimpl->m_puserinteraction->m_ewindowflag & e_window_flag_window_created))
   {
      if (m_puserinteractionimpl->m_puserinteraction->const_layout().design().activation() == e_activation_default)
      {
         m_puserinteractionimpl->m_puserinteraction->layout().m_statea[::user::e_layout_sketch].activation() ==
            e_activation_set_active;
      }

      return;
   }


   //synchronous_lock synchronouslock(user_synchronization());

   {
      windowing_output_debug_string("::set_active_window 1");

      //display_lock displaylock(x11_display()->Display());

      //         XEvent xev;
      //
      //         zero(xev);

      //         auto windowRoot = DefaultRootWindow(Display());
      //
      //         Atom atomActiveWindow = x11_display()->_intern_atom_unlocked("_NET_ACTIVE_WINDOW", False);
      //
      //         xev.xclient.type = ClientMessage;
      //         xev.xclient.send_event = True;
      //         xev.xclient.display = Display();
      //         xev.xclient.window = Window();
      //         xev.xclient.message_type = atomActiveWindow;
      //         xev.xclient.format = 32;
      //         xev.xclient.data.l[0] = 1;
      //         xev.xclient.data.l[1] = 0;
      //         xev.xclient.data.l[2] = 0;
      //         xev.xclient.data.l[3] = 0;
      //         xev.xclient.data.l[4] = 0;
      //
      //         XSendEvent(Display(), windowRoot, False, SubstructureRedirectMask | SubstructureNotifyMask, &xev);
      //
      //         windowing_output_debug_string("::set_active_window 2");
   }

   //auto estatus =
   //
   set_keyboard_focus();

   //struct SDL_WaylandInput * input = data->input;
   //SDL_Window *focus = SDL_GetKeyboardFocus();
   //struct wl_surface *requesting_surface = focus ? focus->driverdata->surface : NULL;

   //__activate_window(true);

   //      if (!estatus)
   //      {
   //
   //         return estatus;
   //
   //      }
   //
   //      return estatus;
}


/// should be run at user_thread
void window::set_foreground_window()
{
   synchronous_lock synchronouslock(user_synchronization());

   //display_lock displaylock(x11_display()->Display());

   _set_foreground_window_unlocked();

   //      XRaiseWindow(Display(), Window());
   //
   //      XSetInputFocus(Display(), Window(), RevertToNone, CurrentTime);

   //return true;
}


/// should be run at user_thread
void window::_set_foreground_window_unlocked()
{
   ////      synchronous_lock synchronouslock(user_synchronization());
   ////
   ////      display_lock displaylock(x11_display()->Display());
   //
   //      XRaiseWindow(Display(), Window());
   //
   //      XSetInputFocus(Display(), Window(), RevertToNone, CurrentTime);
   //
   //      //return true;
}


//   Window window::_get_window_relative(enum_relative erelative, ::Window * windowa, int numItems)
//   {
//
//      if (::is_null(windowa))
//      {
//
//         windowing_output_debug_string("::_get_window_relative");
//
//         return 0;
//
//      }
//
//      ::Window window = 0;
//
//      switch (erelative)
//      {
//
//         case e_relative_first_sibling:
//         {
//
//            window = windowa[0];
//
//         }
//            break;
//
//         case e_relative_last_sibling:
//         {
//
//            window = windowa[numItems - 1];
//
//         }
//            break;
//
//         case e_relative_next_sibling:
//         case e_relative_previous_sibling:
//         {
//
//            int iFound = -1;
//
//            for (int i = 0; i < numItems; i++)
//            {
//
//               if (windowa[i] == Window())
//               {
//
//                  iFound = i;
//
//                  break;
//
//               }
//
//            }
//
//            if (iFound < 0)
//            {
//
//               return 0;
//
//            }
//
//            if (erelative == e_relative_next_sibling)
//            {
//
//               if (iFound + 1 >= numItems)
//               {
//
//                  return 0;
//
//               }
//
//               window = windowa[iFound + 1];
//
//            } else if (erelative == e_relative_previous_sibling)
//            {
//
//               if (iFound - 1 < 0)
//               {
//
//                  return 0;
//
//               }
//
//               window = windowa[iFound - 1];
//
//            } else
//            {
//
//               return 0;
//
//            }
//
//         }
//         default:
//         {
//
//            return 0;
//
//         }
//
//      }
//
//      return window;
//
//   }


//   ::windowing::window * window::get_window(enum_relative erelative)
//   {
//
//      synchronous_lock synchronouslock(user_synchronization());
//
//      ::Window window = 0;
//
//      windowing_output_debug_string("::get_window 1");
//
//      display_lock displaylock(x11_display()->Display());
//
//      if (erelative == e_relative_first_sibling ||
//          erelative == e_relative_last_sibling ||
//          erelative == e_relative_next_sibling ||
//          erelative == e_relative_previous_sibling)
//      {
//
//         ::oswindow oswindowParent = get_parent();
//
//         if (oswindowParent == nullptr)
//         {
//
//            Atom atomNetClientListStacking = x11_display()->intern_atom("_NET_CLIENT_LIST_STACKING", False);
//
//            Atom atomActualType;
//
//            int format;
//
//            unsigned long numItems, bytesAfter;
//
//            ::Window * windowa = nullptr;
//
//            int status = XGetWindowProperty(
//               Display(),
//               RootWindow(Display(), Screen()),
//               atomNetClientListStacking,
//               0L,
//               1024,
//               false,
//               AnyPropertyType,
//               &atomActualType,
//               &format,
//               &numItems,
//               &bytesAfter,
//               (unsigned char **) &windowa);
//
//            if (status >= Success && numItems)
//            {
//
//               window = _get_window_relative(erelative, windowa, numItems);
//
//            }
//
//            if (windowa != NULL)
//            {
//
//               XFree(windowa);
//
//            }
//
//         } else
//         {
//
//            ::Window root = 0;
//            ::Window parent = 0;
//            ::Window * pchildren = nullptr;
//            u32 numItems = 0;
//
//            int status = XQueryTree(Display(), Window(),
//                                    &root, &parent, &pchildren, &numItems);
//
//            if (status >= Success && numItems)
//            {
//
//               window = _get_window_relative(erelative, pchildren, numItems);
//
//            }
//
//            if (pchildren != nullptr)
//            {
//
//               XFree(pchildren);
//
//            }
//
//         }
//
//      } else
//      {
//
//         ::Window root = 0;
//         ::Window parent = 0;
//         ::Window * pchildren = nullptr;
//         u32 numItems = 0;
//
//         int status = XQueryTree(Display(), Window(),
//                                 &root, &parent, &pchildren, &numItems);
//
//         if (status >= Success && numItems)
//         {
//
//            if (erelative == e_relative_first_child)
//            {
//
//               window = pchildren[0];
//
//            } else if (erelative == e_relative_last_child)
//            {
//
//               window = pchildren[numItems - 1];
//
//            }
//
//         }
//
//         if (pchildren != nullptr)
//         {
//
//            XFree(pchildren);
//
//         }
//
//      }
//
//      auto pwindowx11 = x11_display()->_window(window);
//
//      if (::is_null(pwindowx11))
//      {
//
//         return nullptr;
//
//      }
//
//      return pwindowx11;
//
//   }


void window::destroy_window()
{
   bool bOk = false;

   auto puserinteractionimpl = m_puserinteractionimpl;

   if (::is_set(puserinteractionimpl))
   {
      ::pointer<::user::interaction> pinteraction = puserinteractionimpl->m_puserinteraction;

      if (pinteraction.is_set())
      {
         pinteraction->send_message(e_message_destroy, 0, 0);
      }
   }

   // if (::is_set(m_pxdgtoplevel))
   // {
   //
   //    xdg_toplevel_destroy(m_pxdgtoplevel);
   //
   //    m_pxdgtoplevel = nullptr;
   //
   // }
   //
   // if (::is_set(m_pwlsurface))
   // {
   //
   //    wl_surface_destroy(m_pwlsurface);
   //
   // }

   ::windowing::window::destroy_window();

   if (::is_set(puserinteractionimpl))
   {
      ::pointer<::user::interaction> pinteraction = puserinteractionimpl->m_puserinteraction;

      if (pinteraction.is_set())
      {
         pinteraction->send_message(e_message_non_client_destroy, 0, 0);
      }
   }
}


bool window::is_window()
{
   //      if (::oswindow_data::s_pdataptra->find_first(oswindow) < 0)
   //      {
   //
   //         return false;
   //
   //      }

   //return true;

   return true;
}


//   comparable_array<Atom> window::_wm_get_list_unlocked(Atom atomList)
//   {
//
//      comparable_array<Atom> atoma;
//
//      if (atomList == None)
//      {
//
//         return atoma;
//
//      }
//
//      Atom actual_type;
//
//      int actual_format;
//
//      unsigned long int bytes_after;
//
//      Atom * patoms = nullptr;
//
//      long unsigned int num_items = 0;
//
//      XGetWindowProperty(Display(), Window(), atomList, 0, 1024,
//                         False, XA_ATOM, &actual_type, &actual_format,
//                         &num_items,
//                         &bytes_after, (unsigned char **) &patoms);
//
//      atoma.set_size(num_items);
//
//      memcpy(atoma.data(), patoms, atoma.get_size_in_bytes());
//
//      XFree(patoms);
//
//      return atoma;
//
//   }
//
//
//   ::comparable_array < Atom > window::_get_net_wm_state_unlocked()
//   {
//
//      auto pdisplay = x11_display();
//
//      return _wm_get_list_unlocked(pdisplay->m_atomNetWmState);
//
////      bNetWmStateHidden = atoma.contains(pdisplay->m_atomNetWmStateHidden);
////
////      bNetWmStateMaximized = atoma.contains(pdisplay->m_atomNetWmStateMaximizedHorz)
////         || atoma.contains(pdisplay->m_atomNetWmStateMaximizedVert);
////
////      bNetWmStateFocused = atoma.contains(pdisplay->m_atomNetWmStateFocused);
//
//   }
//
//
//   int window::_wm_test_list_unlocked(Atom atomList, Atom atomFlag)
//   {
//
////      synchronous_lock synchronouslock(user_synchronization());
//
//      Atom actual_type;
//
//      int actual_format;
//
//      unsigned long i;
//
//      auto atoma = _wm_get_list_unlocked(atomList);
//
//      if (atoma.is_empty())
//      {
//
//         return 0;
//
//      }
//
//      bool bFind = atoma.contains(atomFlag);
//
//      return bFind ? 1 : 0;
//
//   }
//
//
//   int window::_wm_test_state_unlocked(const char * pszNetStateFlag)
//   {
//
//      //synchronous_lock synchronouslock(user_synchronization());
//
//      Atom atomFlag = x11_display()->_intern_atom_unlocked(pszNetStateFlag, 1);
//
//      if (atomFlag == None)
//      {
//
//         windowing_output_debug_string("ERROR: cannot find atom for " + string(pszNetStateFlag) + "!\n");
//
//         return 0;
//
//      }
//
//      Atom atomNetState = x11_display()->_intern_atom_unlocked("_NET_WM_STATE", 1);
//
//      if (atomNetState == None)
//      {
//
//         windowing_output_debug_string("ERROR: cannot find atom for _NET_WM_STATE !\n");
//
//         return 0;
//
//      }
//
//      return _wm_test_list_unlocked(atomNetState, atomFlag);
//
//   }
//
//
//   int window::wm_test_state(const char * pszNetStateFlag)
//   {
//
//      synchronous_lock synchronouslock(user_synchronization());
//
//      windowing_output_debug_string("::wm_test_state 1");
//
//      display_lock displaylock(x11_display()->Display());
//
//      if (x11_display()->is_null())
//      {
//
//         windowing_output_debug_string("::wm_test_state 1.1");
//
//         return 0;
//
//      }
//
//      int i = _wm_test_state_unlocked(pszNetStateFlag);
//
//      windowing_output_debug_string("::wm_test_state 2");
//
//      return i;
//
//   }
//
//
//   bool window::_wm_add_remove_list_unlocked(Atom atomList, Atom atomFlag, bool bSet)
//   {
//
//      if (atomFlag == None)
//      {
//
//         return false;
//
//      }
//
//      if (atomList == None)
//      {
//
//         return false;
//
//      }
//
//      if (bSet)
//      {
//
//         if (!_wm_test_list_unlocked(atomList, atomFlag))
//         {
//
//            XChangeProperty(Display(), Window(), atomList, XA_ATOM, 32, PropModeAppend, (unsigned char *) &atomFlag, 1);
//
//         }
//
//      }
//      else
//      {
//
//         unsigned long num_items;
//
//         auto atoma = _wm_get_list_unlocked(atomList);
//
//         if (atoma.is_empty())
//         {
//
//            return false;
//
//         }
//
//         auto iFind = -1;
//
//         int i;
//
//         for (i = 0; i < num_items; i++)
//         {
//
//            if (atoma[i] == atomFlag)
//            {
//
//               iFind = i;
//
//               break;
//
//            }
//
//         }
//
//         if (::not_found(iFind))
//         {
//
//            atoma.erase_at(iFind);
//
//            XChangeProperty(Display(), Window(), atomList, XA_ATOM, 32, PropModeReplace, (unsigned char *) atoma.data(),
//                            atoma.size());
//
//         }
//
//      }
//
//      return true;
//
//   }
//
//
// bool window::has_mouse_capture()
// {
//    //
//    //      auto pdisplay = x11_display();
//    //
//    //      if (::is_null(pdisplay))
//    //      {
//    //
//    //         return false;
//    //
//    //      }
//    //
//    //      auto pwindowCapture = pdisplay->m_pwindowMouseCapture;
//    //
//    //      if (::is_null(pwindowCapture))
//    //      {
//    //
//    //         return false;
//    //
//    //      }
//    //
//    //      if (pwindowCapture != this)
//    //      {
//    //
//    //         return false;
//    //
//    //      }
//    //
//    return true;
// }


bool window::has_keyboard_focus() const
{
   //      auto pdisplay = x11_display();
   //
   //      if (::is_null(pdisplay))
   //      {
   //
   //         return false;
   //
   //      }
   //
   //      auto pwindowFocus = pdisplay->m_pwindowKeyboardFocus;
   //
   //      if (::is_null(pwindowFocus))
   //      {
   //
   //         return false;
   //
   //      }
   //
   //      auto pimplFocus = pwindowFocus->m_puserinteractionimpl;
   //
   //      if (::is_null(pimplFocus))
   //      {
   //
   //         return false;
   //
   //      }
   //
   //      auto pinteractionFocus = pimplFocus->m_puserinteraction;
   //
   //      if (::is_null(pinteractionFocus))
   //      {
   //
   //         return false;
   //
   //      }
   //
   //      if (!(pinteractionFocus->m_ewindowflag & ::e_window_flag_focus))
   //      {
   //
   //         return false;
   //
   //      }
   //
   //return m_bHasKeyboardFocus;
   return false;
}

//
//
//   /// should be run in user thread
//   ::e_status window::x11_store_name(const char * pszName)
//   {
//
//      synchronous_lock synchronouslock(user_synchronization());
//
//      display_lock displaylock(x11_display()->Display());
//
//      XStoreName(Display(), Window(), pszName);
//
//      return ::success;
//
//   }
//

//   string window::x11_get_name()
//   {
//
//      string str;
//
//      char *name = NULL;
//      int status = XFetchName(Display(), Window(), &name);
//      if (status >= Success)
//      {
//         str = name;
//      }
//      XFree(name);
//      return str;
//
//   }

//// should be called in user_thread
//   int_bool window::x11_get_window_rect(::rectangle_i32 *prectangle)
//   {
//
//      XWindowAttributes attrs;
//
//      if (!XGetWindowAttributes(Display(), window, &attrs))
//      {
//
//         windowing_output_debug_string("::x11_get_window_rect 1.1 (xgetwindowattributes failed)");
//
//         return false;
//
//      }
//
//      int x = 0;
//
//      int y = 0;
//
//      int screen = XDefaultScreen((Display *) d);
//
//      Window windowRoot = RootWindow((Display *) Display(), screen);
//
//      Window child;
//
//      XTranslateCoordinates(Display(), window, windowRoot, 0, 0, &x, &y, &child);
//
//      prectangle->left() = x + attrs.x;
//
//      prectangle->top() = y + attrs.y;
//
//      prectangle->right() = x + attrs.x + attrs.width;
//
//      prectangle->bottom() = y + attrs.y + attrs.height;
//
//
//      windowing_output_debug_string("::x11_get_window_rect 2");
//
//      return true;
//
//   }

//   int_bool window::this->rectangle(::rectangle_i32 *prectangle)
//   {
//
//      synchronous_lock synchronouslock(user_synchronization());
//
//      display_lock displaylock(x11_display()->Display());
//
//      if (x11_display()->is_null())
//      {
//
//         windowing_output_debug_string("::this->rectangle 1.1 (display is null)");
//
//         return false;
//
//      }
//
//      XWindowAttributes attr;
//
//      if (XGetWindowAttributes(Display(), Window(), &attr) == 0)
//      {
//
//         windowing_output_debug_string("::this->rectangle 1.2 (xgetwindowattributes failed");
//
//         return false;
//
//      }
//
//      prectangle->left() = 0;
//
//      prectangle->top() = 0;
//
//      prectangle->right() = prectangle->left() + attr.width;
//
//      prectangle->bottom() = prectangle->top() + attr.height;
//
//      windowing_output_debug_string("::this->rectangle 2");
//
//      return true;
//
//   }


void window::__update_graphics_buffer()
{
   user_post([this]()
   {
      auto pimpl = m_puserinteractionimpl;

      if (::is_set(pimpl))
      {
         pimpl->m_pgraphicsgraphics->update_screen();
      }
   });

   //}
   //);
}


void window::window_update_screen()
{


   main_post([this]()
   {

      // Queue the drawing area for a redraw
      gtk_widget_queue_draw(m_pdrawingarea);

   });


#ifdef MORE_LOG
      information() << "window_do_update_screen";
#endif

   //      if(m_interlockedPostedScreenUpdate > 0)
   //      {
   //
   //         return;
   //
   //      }
   //
   //      m_interlockedPostedScreenUpdate++;

   //windowing()->windowing_post([this]()
   //                          {

   {
      //         synchronous_lock synchronouslock(user_synchronization());

      //display_lock displayLock(x11_display()->Display());

      //       auto pimpl = m_puserinteractionimpl;

      //         if(m_bDoneFirstMapping)
      //         {
      //
      //            configure_window_unlocked();
      //
      //         }

      //pimpl->m_pgraphicsgraphics->update_screen();

      //pbuffer->update_screen();
   }

   //      auto pimpl = m_puserinteractionimpl;
   //
   //      pimpl->m_pgraphicsthread->on_graphics_thread_iteration_end();

   //                                  });

   //m_interlockedPostedScreenUpdate--;
}


//   void window::_window_request_presentation_locked()
//   {
//
//      synchronous_lock synchronouslock(user_synchronization());
//
//      display_lock displayLock(x11_display()->Display());
//
//      auto pimpl = m_puserinteractionimpl;
//
//      if (::is_set(pimpl))
//      {
//
//         pimpl->_window_request_presentation_unlocked();
//
//      }
//
//   }


//   void window::_on_visual_changed_unlocked()
//   {
//
//   }


//   void window::set_mouse_capture()
//   {
//
//      auto pthread = m_puserinteractionimpl->m_puserinteraction->m_pthreadUserInteraction;
//
//      windowing()->set_mouse_capture(pthread, this);
//
//      //::pointer < ::windowing_gtk4::display > pwaylanddisplay = m_pnanouserdisplay;
//
//      //pwaylanddisplay->__capture_mouse(this, pwaylanddisplay->m_uLastButtonSerial);
//
//
////      m_pwindowing->windowing_post([this]()
////                                   {
////
////                                      synchronous_lock synchronouslock(user_synchronization());
////
//////                                      display_lock displaylock(x11_display()->Display());
////
////                                      information() << "XGrabPointer";
//////
//////                                      auto grabStatus = XGrabPointer(Display(), Window(), False,
//////                                                                     ButtonPressMask | ButtonReleaseMask |
//////                                                                     PointerMotionMask,
//////                                                                     GrabModeAsync, GrabModeAsync, None, None,
//////                                                                     CurrentTime);
////
//////                                      if (grabStatus != GrabSuccess)
//////                                      {
//////
//////                                         windowing_output_debug_string("\noswindow_data::SetCapture 2.1");
//////
//////                                         return;
//////
//////                                      }
////
//////                                      auto pdisplay = x11_display();
//////
//////                                      if (pdisplay)
//////                                      {
//////
//////                                         pdisplay->_on_capture_changed_to(this);
//////
//////                                      }
////
////                                      windowing_output_debug_string("\noswindow_data::SetCapture 2");
////
////                                   });
////
////      //return ::success;
//
//   }
//
//
//   void window::release_mouse_capture()
//   {
//
//      auto pthread = m_puserinteractionimpl->m_puserinteraction->m_pthreadUserInteraction;
//
//      windowing()->release_mouse_capture(pthread);
//
//   }


void window::set_keyboard_focus()
{
   synchronous_lock synchronouslock(user_synchronization());

   // if (m_pwlsurface == nullptr)
   // {
   //
   //    return;
   //
   //    //throw ::exception(error_failed);
   //
   // }
   //
   // windowing_output_debug_string("\nwindow(x11)::set_keyboard_focus 1");
   //
   // //display_lock displaylock(x11_display()->Display());

   _set_keyboard_focus_unlocked();

   //      if (!is_window())
   //      {
   //
   //         windowing_output_debug_string("\nwindow(x11)::set_keyboard_focus 1.1");
   //
   //         throw ::exception(error_failed);
   //
   //      }
   //
   //      if (!XSetInputFocus(Display(), Window(), RevertToNone, CurrentTime))
   //      {
   //
   //         windowing_output_debug_string("\nwindow(x11)::set_keyboard_focus 1.3");
   //
   //         throw ::exception(error_failed);
   //
   //      }
   //
   //      windowing_output_debug_string("\nwindow(x11)::set_keyboard_focus 2");

   //return ::success;
}


void window::_set_keyboard_focus_unlocked()
{
   //synchronous_lock synchronouslock(user_synchronization());

   //       if (m_pwlsurface == 0)
   //       {
   //
   //          throw ::exception(error_failed);
   //
   //       }
   //
   //       windowing_output_debug_string("\nwindow(x11)::set_keyboard_focus 1");
   //
   //       //display_lock displaylock(x11_display()->Display());
   //
   //       if (!is_window())
   //       {
   //
   //          windowing_output_debug_string("\nwindow(x11)::set_keyboard_focus 1.1");
   //
   //          throw ::exception(error_failed);
   //
   //       }
   //
   // //      if (!XSetInputFocus(Display(), Window(), RevertToNone, CurrentTime))
   // //      {
   // //
   // //         windowing_output_debug_string("\nwindow(x11)::set_keyboard_focus 1.3");
   // //
   // //         throw ::exception(error_failed);
   // //
   // //      }
   //
   //       windowing_output_debug_string("\nwindow(x11)::set_keyboard_focus 2");
   //
   //       //return ::success;
}


bool window::is_active_window() const
{
   return ::windowing::window::is_active_window();
}


void window::bring_to_front()
{
   //       synchronous_lock synchronouslock(user_synchronization());
   //
   //       if (m_pwlsurface == 0)
   //       {
   //
   //          throw ::exception(error_failed);
   //
   //       }
   //
   //       windowing_output_debug_string("\nwindow(x11)::set_keyboard_focus 1");
   //
   // //      display_lock displaylock(x11_display()->Display());
   // //
   // //      XRaiseWindow(displaylock.m_pnanouserdisplay, Window());
   //
   //       //return ::success;
}


//   bool window::presentation_complete()
//   {
//
//      return m_puserinteractionimpl->m_pgraphics->presentation_complete();
//
//   }


void window::_on_end_paint()
{
   //      if(m_enetwmsync == window::e_net_wm_sync_wait_paint)
   //      {
   //
   //         m_enetwmsync == window::e_net_wm_sync_none;
   //
   //         if (!XSyncValueIsZero(m_xsyncvalueNetWmSync))
   //         {
   //
   //            x_change_property(
   //               x11_display()->m_atomNetWmSyncRequestCounter,
   //               XA_CARDINAL,
   //               32,
   //               PropModeReplace,
   //               (const unsigned char *) &m_xsyncvalueNetWmSync, 1);
   //
   //            XSyncIntToValue(&m_xsyncvalueNetWmSync, 0);
   //
   //         }
   //
   //      }
   //
}


//   void window::_enable_net_wm_sync()
//   {
//
//      if (m_xsynccounterNetWmSync != None)
//      {
//
//         return;
//
//      }
//
//      //return;
//
//      auto atomWmProtocols = x11_display()->m_atomWmProtocols;
//
//      auto atomNetWmSyncRequest = x11_display()->m_atomNetWmSyncRequest;
//
//      m_enetwmsync = e_net_wm_sync_none;
//
//      _wm_add_remove_list_unlocked(atomWmProtocols, atomNetWmSyncRequest, true);
//
//      {
//
//         XSyncValue xsyncvalue;
//
//         XSyncIntToValue(&xsyncvalue, 1);
//
//         m_xsynccounterNetWmSync = XSyncCreateCounter(x11_display()->Display(), xsyncvalue);
//
//      }
//
//      auto atomNetWmSyncRequestCounter = x11_display()->m_atomNetWmSyncRequestCounter;
//
//      x_change_property(atomNetWmSyncRequestCounter,
//                        XA_CARDINAL, 32, PropModeReplace, (const unsigned char *) &m_xsynccounterNetWmSync,
//                        1);
//
//      XSyncIntToValue(&m_xsyncvalueNetWmSyncPending, 0);
//
//      XSyncIntToValue(&m_xsyncvalueNetWmSync, 0);
//
//   }


//    void window::__handle_pointer_enter(::wl_pointer * pwlpointer)
//    {
//
//       information() << "__handle_pointer_enter";
//
//       //::wayland::nano::user::window_base::__handle_pointer_enter(pwlpointer);
//
//       //m_pointCursor2 = m_pointPointer;
//
//    }
//
//
//    void window::__handle_pointer_motion(::wl_pointer * pwlpointer, ::u32 millis)
//    {
//
//       //m_pwlpointer = pwlpointer;
//
//       //::wayland::nano::user::window_base::__handle_pointer_motion(pwlpointer, millis);
//
//       //m_pointCursor2 = m_pointPointer;
//
//       auto puserinteractionimpl = m_puserinteractionimpl;
//
//       if(::is_set(puserinteractionimpl))
//       {
//
//          auto pmouse = __create_new<::message::mouse>();
//
//          pmouse->m_oswindow = this;
//
//          pmouse->m_pwindow = this;
//
//          pmouse->m_atom = e_message_mouse_move;
//
//          pmouse->m_pointHost = m_pointCursor2;
//
//          pmouse->m_pointAbsolute = m_pointCursor2;
//
//          pmouse->m_time.m_iSecond = millis / 1_k;
//
//          pmouse->m_time.m_iNanosecond = (millis % 1_k) * 1_M;
//
//          //pwindow->message_handler(pmouse);
//
//          //wayland_windowing()->post_ui_message(pmouse);
//
//          puserinteractionimpl->message_handler(pmouse);
//
//       }
//
//    }
//
//
//    void window::__handle_pointer_leave(::wl_pointer * pwlpointer, ::windowing_gtk4::window * pwaylandwindowLeave)
//    {
//
//       ::string strType = ::type(m_puserinteractionimpl->m_puserinteraction).name();
//
//       information()
//
//          << "__handle_pointer_leave";
//
//       //m_pwlpointer = pwlpointer;
//
// //            if (msg.oswindow)
// //            {
// //
// //               ::minimum(m_pointCursor.x());
// //
// //               ::minimum(m_pointCursor.y());
// //
// //
// //               if(e.xcrossing.mode == NotifyUngrab)
// //               {
// //
// //                  information() << "X11 LeaveNotify NotifyUngrab";
// //
// //               }
// //
// ////            if(e.xcrossing.mode == NotifyUngrab)
// ////            {
// ////
// ////  //             MESSAGE msgCaptureChanged;
// ////
// //////               msgCaptureChanged.oswindow = m_pwindowCapture;
// ////               msg.m_atom = e_message_capture_changed;
// ////               msg.wParam = 0;
// ////               msg.lParam = (lparam) (oswindow) (msg.oswindow == m_pwindowCapture ? nullptr : m_pwindowCapture.m_p);
// ////               msg.time = e.xcrossing.time;
// ////
// ////               post_ui_message(msg);
// ////
// ////            }
//
//
// //
//
//       ::minimum(m_pointCursor2.x());
//
//       ::minimum(m_pointCursor2.y());
//
// //      MESSAGE msg;
// //      msg.oswindow = ::is_set(pwaylandwindowLeave) ? pwaylandwindowLeave : this;
// //      msg.m_atom = e_message_mouse_leave;
// //      msg.wParam = 0;
// //      msg.lParam = 0;
// //      //   msg.time = e.xcrossing.time;
// //      msg.time = 0;
// //
// //      wayland_windowing()->post_ui_message(msg);
//
//       auto pmouse = __create_new<::message::mouse>();
//
//       pmouse->m_oswindow = ::is_set(pwaylandwindowLeave) ? pwaylandwindowLeave : this;
//
//       pmouse->m_pwindow = pmouse->m_oswindow;
//
//       pmouse->m_atom = e_message_mouse_leave;
//
//       pmouse->m_pointHost = m_pointCursor2;
//
//       pmouse->m_pointAbsolute = m_pointCursor2;
//
//       //pmouse->m_time.m_iSecond = millis / 1_k;
//
//       //pmouse->m_time.m_iNanosecond = (millis % 1_k) * 1_M;
//
//       //msg.wParam = 0;
//
//       //msg.lParam = make_i32(e.xbutton.x_root, e.xbutton.y_root);
//
//       //post_ui_message(msg);
//       //wayland_windowing()->post_ui_message(pmouse);
//
//       m_puserinteractionimpl->message_handler(pmouse);
//
// //            }
//
//    }
//
//
//    void window::__handle_pointer_button(::wl_pointer * pwlpointer, ::u32 linux_button, ::u32 pressed, ::u32 millis)
//    {
//
//       //::string strType = ::type(m_puserinteractionimpl->m_puserinteraction).name();
//
//       //m_pwlpointer = pwlpointer;
//
//       enum_message emessage = e_message_undefined;
//
//       //msg.m_atom = e_message_mouse_wheel;
//
//       //post_ui_message(pmouse);
//
//       bool bRet = true;
//
//       //msg.time = e.xbutton.time;
//
//       int Δ = 0;
//
//       if (pressed == WL_POINTER_BUTTON_STATE_PRESSED)
//       {
//
//          ::point_i32 m_pointWindowDragStart;
//
//          if (linux_button == BTN_LEFT)
//          {
//
//             information() << "LeftButtonDown";
//
//             emessage = e_message_left_button_down;
//
//          }
//          else if (linux_button == BTN_MIDDLE)
//          {
//
//             emessage = e_message_middle_button_down;
//
//          }
//          else if (linux_button == BTN_RIGHT)
//          {
//
//             emessage = e_message_right_button_down;
//
//          }
//          else if (linux_button == BTN_GEAR_DOWN)
//          {
//
//             Δ = 120;
//
//          }
//          else if (linux_button == BTN_GEAR_UP)
//          {
//
//             Δ = -120;
//
//          }
//          else
//          {
//
//             bRet = false;
//
//          }
//
//       }
//       else if (pressed == WL_POINTER_BUTTON_STATE_RELEASED)
//       {
//
//          if (linux_button == BTN_LEFT)
//          {
//
//             information()
//                << "LeftButtonUp";
//
//             emessage = e_message_left_button_up;
//
//          }
//          else if (linux_button == BTN_MIDDLE)
//          {
//
//             emessage = e_message_middle_button_up;
//
//          }
//          else if (linux_button == BTN_RIGHT)
//          {
//
//             emessage = e_message_right_button_up;
//
//          }
//          else
//          {
//
//             bRet = false;
//
//          }
//
//       }
//       else
//       {
//
//          bRet = false;
//
//       }
//
//       //m_pointCursor2 = m_pointPointer;
//
// //      MESSAGE msg;
// //
// //      msg.oswindow = this;
// //
// //      msg.oswindow->set_cursor_position(m_pointCursor);
//
//
//
// //      int l = msg.oswindow->m_pimpl->m_puserinteraction->layout().sketch().m_point.x;
// //      int t = msg.oswindow->m_pimpl->m_puserinteraction->layout().sketch().m_point.y;
// //      int w = msg.oswindow->m_pimpl->m_puserinteraction->layout().sketch().m_size.cx();
// //      int h = msg.oswindow->m_pimpl->m_puserinteraction->layout().sketch().m_size.cy();
// //
// //      ::rectangle_i32 r;
// //
// //      window_rectangle(msg.oswindow, &r);
// //
// //      int l1 = r.left();
// //      int t1 = r.top();
// //      int w1 = r.width();
// //      int h1 = r.height();
//
//       if (Δ != 0)
//       {
//
//          auto pmousewheel = __create_new<::message::mouse_wheel>();
//
//          pmousewheel->m_oswindow = this;
//
//          pmousewheel->m_pwindow = this;
//
//          pmousewheel->m_atom = e_message_mouse_wheel;
//
//          //msg.wParam = make_i32(0, iDelta);
//
//          //msg.lParam = make_i32(e.xbutton.x_root, e.xbutton.y_root);
//
//          pmousewheel->m_Δ = Δ;
//
//          pmousewheel->m_pointHost = m_pointCursor2;
//
//          pmousewheel->m_pointAbsolute = m_pointCursor2;
//
//          pmousewheel->m_time.m_iSecond = millis / 1_k;
//
//          pmousewheel->m_time.m_iNanosecond = (millis % 1_k) * 1_M;
//
//          //wayland_windowing()->post_ui_message(pmousewheel);
//
//          m_puserinteractionimpl->message_handler(pmousewheel);
//
//       }
//       else if (bRet)
//       {
//
//          auto pmouse = __create_new<::message::mouse>();
//
//          pmouse->m_oswindow = this;
//
//          pmouse->m_pwindow = this;
//
//          pmouse->m_atom = emessage;
//
//          pmouse->m_pointHost = m_pointCursor2;
//
//          pmouse->m_pointAbsolute = m_pointCursor2;
//
//          pmouse->m_time.m_iSecond = millis / 1_k;
//
//          pmouse->m_time.m_iNanosecond = (millis % 1_k) * 1_M;
//
//          //msg.wParam = 0;
//
//          //msg.lParam = make_i32(e.xbutton.x_root, e.xbutton.y_root);
//
//          //post_ui_message(msg);
//          //wayland_windowing()->post_ui_message(pmouse);
//
//          m_puserinteractionimpl->message_handler(pmouse);
//
//       }
//
//    }
// //
// //
// //   void window::__defer_update_wayland_buffer()
// //   {
// //
// //      if(m_uLastConfigureSerial && m_waylandbuffer.m_size != m_sizeWindow)
// //      {
// //
// //         auto pdisplaywayaland = dynamic_cast < ::windowing_gtk4::display * > (m_pnanouserdisplay.m_p);
// //
// //         pdisplaywayaland->destroy_wayland_buffer(m_waylandbuffer);
// //
// //         pdisplaywayaland->update_wayland_buffer(m_waylandbuffer, m_sizeWindow);
// //
// //         //wl_surface_attach(m_pwlsurface, m_waylandbuffer.m_pwlbuffer, 0, 0);
// //
// //         //m_puserinteractionimpl->m_puserinteraction->set_need_redraw();
// //
// //         //m_puserinteractionimpl->m_puserinteraction->post_redraw();
// //
// //      }
// //      //wl_surface_damage(surface, 0, 0, WIDTH, HEIGHT);
// //      //wl_surface_commit(m_pwlsurface);
// //
// //   }
// //
// //
// //   void window::__defer_xdg_surface_ack_configure()
// //   {
// //
// //      if(m_uLastAckSerial < m_uLastConfigureSerial)
// //      {
// //
// //         m_uLastAckSerial = m_uLastConfigureSerial;
// //
// //         xdg_surface_ack_configure(m_pxdgsurface, m_uLastAckSerial);
// //
// //         ::string strType = ::type(m_puserinteractionimpl->m_puserinteraction).name();
// //
// //         information()
// //
// //            << "xdg_surface_ack_configure : " << m_uLastAckSerial;
// //
// //      }
// //
// //   }
// //
// //
// //   void window::__handle_xdg_surface_configure(::u32 serial)
// //   {
// //
// //      ::string strType = ::type(m_puserinteractionimpl->m_puserinteraction).name();
// //
// //      information()
// //
// //         << "__handle_xdg_surface_configure : " << serial;
// //
// //      if(!m_bXdgInitialConfigure)
// //      {
// //
// //         m_bXdgInitialConfigure = true;
// //
// //      }
// //
// //      m_uLastConfigureSerial = serial;
// //
// //      auto puserinteractionimpl = m_puserinteractionimpl;
// //
// //      if(puserinteractionimpl)
// //      {
// //
// //         auto puserinteraction = m_puserinteractionimpl->m_puserinteraction;
// //
// //         if(puserinteraction)
// //         {
// //
// //            puserinteraction->set_need_redraw();
// //
// //            puserinteraction->post_redraw();
// //
// //         }
// //
// //      }
// //
// ////
// ////
// ////      if(m_bFirstConfigure)
// ////      {
// ////
// ////         m_bFirstConfigure = false;
// ////
// ////         __continue_initialization_after_configure();
// ////
// ////      }
// //
// //   }
//
//
//    void window::__handle_xdg_toplevel_configure(::i32 width, ::i32 height, ::wl_array * pwlarrayState)
//    {
//
// //      ::string strType = ::type(m_puserinteractionimpl->m_puserinteraction).name();
// //
// //      ::size_i32 size(width, height);
// //
// //      information()
// //
// //         << "__handle_xdg_toplevel_configure input size : " << size;
// //
// //      if(size.cx() > 0)
// //      {
// //
// //         m_sizeWindow.cx() = size.cx();
// //
// //      }
// //
// //      if(size.cy() > 0)
// //      {
// //
// //         m_sizeWindow.cy() = size.cy();
// //
// //      }
// //
// //      m_sizeConfigure = m_sizeWindow;
//
//       ::wayland::nano::user::window_base::__handle_xdg_toplevel_configure(width, height, pwlarrayState);
//
//       information()
//
//          << "__handle_xdg_toplevel_configure effective size : " << m_sizeWindow;
//
//       if (pwlarrayState->size == 0)
//       {
//
//          information()
//
//             << "pwlarrayState is EMPTY";
//
//       }
//       else
//       {
//
//          if (::wayland::nano::user::xdg_toplevel_state_array_contains(pwlarrayState, XDG_TOPLEVEL_STATE_MAXIMIZED))
//          {
//
//             information() << "pwlarrayState contains XDG_TOPLEVEL_STATE_MAXIMIZED";
//
//          }
//
//          if (::wayland::nano::user::xdg_toplevel_state_array_contains(pwlarrayState, XDG_TOPLEVEL_STATE_FULLSCREEN))
//          {
//
//             information() << "pwlarrayState contains XDG_TOPLEVEL_STATE_FULLSCREEN";
//
//          }
//
//          if (::wayland::nano::user::xdg_toplevel_state_array_contains(pwlarrayState, XDG_TOPLEVEL_STATE_ACTIVATED))
//          {
//
//             information() << "pwlarrayState contains XDG_TOPLEVEL_STATE_ACTIVATED";
//
//             if (m_puserinteractionimpl->m_puserinteraction->const_layout().window().display() == ::e_display_iconic)
//             {
//
//                ::string strType = ::type(m_puserinteractionimpl->m_puserinteraction).name();
//
//                information() << "Window was iconic type : " << strType;
//
//                if (::wayland::nano::user::xdg_toplevel_state_array_contains(pwlarrayState, XDG_TOPLEVEL_STATE_MAXIMIZED))
//                {
//
//                   m_puserinteractionimpl->m_puserinteraction->display(::e_display_zoomed);
//
//                }
//                else if (::wayland::nano::user::xdg_toplevel_state_array_contains(pwlarrayState, XDG_TOPLEVEL_STATE_FULLSCREEN))
//                {
//
//                   m_puserinteractionimpl->m_puserinteraction->display(::e_display_full_screen);
//
//                }
//                else
//                {
//
//                   m_puserinteractionimpl->m_puserinteraction->display(::e_display_normal);
//
//                }
//
//             }
//
//          }
//
//       }
//
//       m_puserinteractionimpl->m_puserinteraction->set_size(m_sizeWindow);
//
//    }
//
//
//    void window::_on_simple_key_message(::user::e_key ekey, ::enum_message emessage)
//    {
//
//       // TODO when do we get WL_KEYBOARD_KEY_STATE_REPEAT?
//       if (ekey != ::user::e_key_none)
//       {
//
//          auto pkey = __create_new<::message::key>();
//
//          pkey->
//             m_oswindow = this;
//
//          pkey->
//             m_pwindow = this;
//
//          pkey->
//             m_ekey = ekey;
//
//          if (emessage == e_message_key_down)
//          {
//
//             pkey->
//                m_atom = e_message_key_down;
//
//             information()
//
//                << "e_message_key_down";
//
//          }
//          else
//          {
//
//             pkey->
//                m_atom = e_message_key_up;
//
// //information() << "e_message_key_up : " << (iptr) ekey;
//
//             information()
//
//                << "e_message_key_up";
//
//          }
//
//          m_puserinteractionimpl->
//             message_handler(pkey);
//
//       }
//
//    }

//
//    void window::_on_text_composition(const ::scoped_string & scopedstrText)
//    {
//
//    //Wayland_data_device_set_serial(input->data_device, serial);
//
//    auto pkey = __create_new<::message::key>();
//
//    pkey->
//    m_oswindow = this;
//
//    pkey->
//    m_pwindow = this;
//
//    pkey->
//    m_atom = e_message_text_composition;
//
//    pkey->
//    m_strText = scopedstrText;
//
//    information()
//
//    << "e_message_text_composition";
//
//    m_puserinteractionimpl->
//    message_handler(pkey);
//
// }


// bool window::defer_perform_entire_resizing_process(::experience::enum_frame eframeSizing, ::user::mouse * pmouse)
// {
//
//       auto pdisplay = gtk4_display();
//
//       if (pdisplay->is_wayland())
//       {
//
//          guint button;
//
//          if(::is_null(pmouse))
//          {
//
//             button = 1;
//
//          }
//          else
//          {
//
//             button= as_guint_button(pmouse->m_ebuttonstate);
//
//          }
//
//
//
//          //guint button = gtk_gesture_single_get_current_button(GTK_GESTURE_SINGLE(pclick));
//          //Cast to Wayland display
//          //struct wl_display *wl_display = gdk_wayland_display_get_wl_display(display);
//
//
//          // Get the Wayland compositor (xdg_wm_base is part of the Wayland compositor)
//          //struct wl_compositor *wl_compositor = gdk_wayland_display_get_wl_compositor(display);
//
//          // Get the wl_surface from the GTK window
//          //auto gdk_surface = gtk_native_get_surface(GTK_NATIVE(m_pgtkwidget));
//
//          //struct wl_surface *pwlsurface = gdk_wayland_surface_get_wl_surface(gdk_surface);
//
//          // You need to create an xdg_surface using xdg_wm_base
//          //struct xdg_wm_base *pxdgwmbase = gtk4_windowing()->m_pnanouserdisplay->m_pxdgwmbase;
//
//          // GdkEventSequence *sequence = gtk_gesture_get_last_updated_sequence(GTK_GESTURE(pclick));
//          //
//          // // Get the GdkEvent from the sequence
//          // GdkEvent *event = gtk_gesture_get_last_event(GTK_GESTURE(pclick), sequence);
//          // if (!event) {
//          //    g_print("Failed to get event from GdkGestureClick.\n");
//          //    return;
//          // }
//          //
//          // guint32 timestamp = gdk_event_get_time (event);
//
//          //GdkWaylandEventSource  peventsource * =gdk_event_get_event_sequence(event);
//
//          guint32 timestamp;
//
//          if(::is_null(pmouse))
//          {
//
//             timestamp = GDK_CURRENT_TIME;
//
//          }
//          else
//          {
//             timestamp=  pmouse->m_iTimestamp;
//          }
//
//          //auto pgdkeventsequence = gdk_event_get_event_sequence(event);
//
//          auto toplevel = gtk_native_get_surface(GTK_NATIVE(m_pgtkwidget));
//
//
//          auto pgdkdisplay = pdisplay->m_pgdkdisplay;
//
//          GdkSeat * pgdkseat = gdk_display_get_default_seat(pgdkdisplay);
//
//          // Get the default pointer device (e.g., mouse)
//          GdkDevice *pgdkdevicePointer = gdk_seat_get_pointer(pgdkseat);
//
//          auto gdksurfacedge = as_gdk_surface_edge(eframeSizing);
//
//          //_unlocked_defer_start_resize(resize_edge, pgesture, x, y);
//
//          double x;
//          double y;
//          if(::is_null(pmouse))
//          {
//             x = 8;
//             y = 8;
//          }
//          else
//          {
//             x = pmouse->m_pointAbsolute.x();
//             y = pmouse->m_pointAbsolute.y();
//          }
//
//          gdk_toplevel_begin_resize(GDK_TOPLEVEL(toplevel), gdksurfacedge, pgdkdevicePointer, button, x, y, timestamp);
//
//
//
//          // Check if the backend is Wayland
//          //if (GDK_IS_WAYLAND_DISPLAY(gdk_display_get_default())) {
//             // Extract the Wayland event serial
//          //guint32 serial = gdk_wayland_event_source_get_event_serial(event);
//          //guint32 serial = wl_message_get_opcode(wl_message_from_opcode(object, opcode));
//
//          // guint32 serial = 0;
//          //
//          // auto pxdgsurface = xdg_wm_base_get_xdg_surface(pxdgwmbase, pwlsurface);
//          //
//          // auto pxdgtoplevel = xdg_surface_get_toplevel(pxdgsurface);
//          // // Get the seat (which manages input devices for the display)
//          // GdkSeat *seat = gdk_display_get_default_seat(display);
//          //
//          // // Get the default pointer device (e.g., mouse)
//          // GdkDevice *pointer = gdk_seat_get_pointer(seat);
//          // auto pwlseat = gdk_wayland_device_get_wl_seat(pointer);
//          //
//          // auto resizeedge = as_xdg_toplevel_resize_edge(eedge);
//          //
//          // xdg_toplevel_resize(
//          //           pxdgtoplevel,
//          //              pwlseat,
//          //              serial,
//          //              resizeedge);
//          //
//          // wl_display_dispatch(wl_display);
//          //
//          //
//          // wl_display_flush(wl_display);
//          //
//          // // Get the GdkSurface for the GTK window
//          // GdkSurface *gdk_surface = gtk_native_get_surface(GTK_NATIVE(window));
//          //
//          // // Get the Wayland surface associated with the GdkSurface
//          // struct wl_surface *wl_surface = gdk_wayland_window_get_wl_surface(GDK_WAYLAND_SURFACE(gdk_surface));
//          //
//          // if (!wl_surface) {
//          //    g_print("Failed to get Wayland surface\n");
//          //    return;
//          // }
//
//          // // Get the Wayland display
//          // struct wl_display *wl_display = gdk_wayland_display_get_wl_display(gdk_display_get_default());
//          //
//          // // Get the Wayland toplevel object (xdg_toplevel)
//          // struct xdg_toplevel *xdg_toplevel = gdk_wayland_window_get_xdg_toplevel(GDK_WAYLAND_SURFACE(gdk_surface));
//          //
//          // if (!xdg_toplevel) {
//          //    g_print("Failed to get xdg_toplevel\n");
//          //    return;
//          // }
//          //
//          // // Trigger the resize operation on the toplevel
//          // // Edges should be a combination of values like XDG_TOPLEVEL_RESIZE_EDGE_LEFT, XDG_TOPLEVEL_RESIZE_EDGE_RIGHT, etc.
//          // guint32 serial = 0;  // You need the serial of the last user event, e.g., from a button press
//          // xdg_toplevel_resize(xdg_toplevel, gdk_wayland_display_get_seat(gdk_display_get_default()), serial, edges);
//          //
//          // g_print("Called xdg_toplevel_resize\n");
//          //
//          // // Flush the display to send the request
// return true;
//       }
//
//    return false;
// }


//      //windowing()->windowing_post([this]()
//        //                          {
//
//      auto pxdgtoplevel = m_pxdgtoplevel;
//
//      if(::is_set(pxdgtoplevel))
//      {
//
//         auto pwlseat = wayland_display()->m_pwlseat;
//
//         auto uSerial = wayland_display()->m_uLastButtonSerial;
//
//         xdg_toplevel_move(pxdgtoplevel, pwlseat, uSerial);
//
//      }
//
//          //                        });
////      while (wl_display_dispatch(wayland_display()->m_pwldisplay) != -1)
////      {
////
////
////      }
//
//      return true;
//
//   }
//
//
// bool window::defer_perform_entire_reposition_process(::user::mouse * pmouse)
// {
//    //return _perform_entire_resizing_process(eframeSizing);
//
//       auto pdisplay = gtk4_display();
//
//       if (pdisplay->is_wayland())
//       {
//          guint button;
//
//          if(::is_null(pmouse))
//          {
//
//             button = 0;
//
//          }
//          else
//          {
//
//             button= as_guint_button(pmouse->m_ebuttonstate);
//
//          }
//
//
//          //guint button = gtk_gesture_single_get_current_button(GTK_GESTURE_SINGLE(pclick));
//          //Cast to Wayland display
//          //struct wl_display *wl_display = gdk_wayland_display_get_wl_display(display);
//
//
//          // Get the Wayland compositor (xdg_wm_base is part of the Wayland compositor)
//          //struct wl_compositor *wl_compositor = gdk_wayland_display_get_wl_compositor(display);
//
//          // Get the wl_surface from the GTK window
//          //auto gdk_surface = gtk_native_get_surface(GTK_NATIVE(m_pgtkwidget));
//
//          //struct wl_surface *pwlsurface = gdk_wayland_surface_get_wl_surface(gdk_surface);
//
//          // You need to create an xdg_surface using xdg_wm_base
//          //struct xdg_wm_base *pxdgwmbase = gtk4_windowing()->m_pnanouserdisplay->m_pxdgwmbase;
//
//          // GdkEventSequence *sequence = gtk_gesture_get_last_updated_sequence(GTK_GESTURE(pclick));
//          //
//          // // Get the GdkEvent from the sequence
//          // GdkEvent *event = gtk_gesture_get_last_event(GTK_GESTURE(pclick), sequence);
//          // if (!event) {
//          //    g_print("Failed to get event from GdkGestureClick.\n");
//          //    return;
//          // }
//          //
//          // guint32 timestamp = gdk_event_get_time (event);
//
//          //GdkWaylandEventSource  peventsource * =gdk_event_get_event_sequence(event);
//
//          guint32 timestamp;
//
//          if(::is_null(pmouse))
//          {
//
//             timestamp = GDK_CURRENT_TIME;
//
//          }
//          else
//          {
//             timestamp=  pmouse->m_iTimestamp;
//          }
//
//          //auto pgdkeventsequence = gdk_event_get_event_sequence(event);
//
//          auto toplevel = gtk_native_get_surface(GTK_NATIVE(m_pgtkwidget));
//
//
//          auto pgdkdisplay = pdisplay->m_pgdkdisplay;
//
//          GdkSeat * pgdkseat = gdk_display_get_default_seat(pgdkdisplay);
//
//          // Get the default pointer device (e.g., mouse)
//          GdkDevice *pgdkdevicePointer = gdk_seat_get_pointer(pgdkseat);
//          double x;
//          double y;
//          if(::is_null(pmouse))
//          {
//             x = gtk_widget_get_width(m_pgtkwidget);
//             y = gtk_widget_get_height(m_pgtkwidget);
//
//             x/=2;
//             y/=2;
//          }
//          else
//          {
//             x = pmouse->m_pointAbsolute.x();
//             y = pmouse->m_pointAbsolute.y();
//          }
//
//
//          gdk_toplevel_begin_move(GDK_TOPLEVEL(toplevel), pgdkdevicePointer, button, x, y, timestamp);
//
//          return true;
//       }
//    return false;
// }


//      xdg_toplevel_resize_edge resizeedge = XDG_TOPLEVEL_RESIZE_EDGE_NONE;
//
//      ::copy(&resizeedge, &eframeSizing);
//
//      if(resizeedge == XDG_TOPLEVEL_RESIZE_EDGE_NONE)
//      {
//
//         return true;
//
//      }
//
//      information() << "defer_perform_entire_resizing_process resizeedge : " << (::iptr) resizeedge;
//
//      //windowing()->windowing_post([this, resizeedge]()
//        //                          {
//
//       if(::is_set(m_pxdgtoplevel))
//       {
//
//          m_resizeedge = resizeedge;
//
//          xdg_toplevel_resize(
//             m_pxdgtoplevel,
//             wayland_display()->m_pwlseat,
//             wayland_display()->m_uLastButtonSerial,
//             resizeedge);
//
//          //});
//       }
//
//      return true;
//
//   }


   bool window::defer_perform_entire_reposition_process(::user::mouse * pmouse)
   {

      return ::gtk4::nano::user::window::defer_perform_entire_reposition_process(pmouse);

   }


   bool window::defer_perform_entire_resizing_process(::experience::enum_frame eframeSizing, ::user::mouse * pmouse)
   {

      return ::gtk4::nano::user::window::defer_perform_entire_resizing_process(eframeSizing, pmouse);

   }



void window::on_destruct_mouse_message(::message::mouse* pmouse)
{
   ::windowing::window::on_destruct_mouse_message(pmouse);

   //      if(::is_null(pmouse))
   //      {
   //
   //         return;
   //
   //      }
   //
   //      try
   //      {
   //
   //         if(pmouse->m_pcursor)
   //         {
   //
   //            windowing()->aaa_set_mouse_cursor(pmouse->m_pcursor);
   //
   //         }
   //         else
   //         {
   //
   //            windowing()->aaa_set_mouse_cursor(get_mouse_cursor());
   //
   //         }
   //
   //      }
   //      catch(...)
   //      {
   //
   //      }
}

//
// void window::__handle_keyboard_enter(::wl_keyboard *pwlkeyboard, uint32_t serial, ::wl_array *pwlarrayKeys)
// {
//
//    information() << "__handle_keyboard_enter";
//
//    ::wayland::nano::user::window_base::__handle_keyboard_enter(pwlkeyboard, serial, pwlarrayKeys);
//
// }
//
//
// void window::__handle_keyboard_leave(::wl_keyboard *pwlkeyboard, uint32_t serial)
// {
//
//    information() << "__handle_keyboard_leave";
//
//    ::wayland::nano::user::window_base::__handle_keyboard_leave(pwlkeyboard, serial);
//
// }


//   void window::__handle_keyboard_key(::wl_keyboard *pwlkeyboard, uint32_t serial, uint32_t time, uint32_t key, uint32_t pressed)
//   {
//
//      if (key < ARRAY_SIZE(xfree86_key_table2))
//      {
//
//         auto ekey = xfree86_key_table2[key];
//
//         // TODO when do we get WL_KEYBOARD_KEY_STATE_REPEAT?
//         if (ekey != ::user::e_key_none)
//         {
//
//            auto pkey = __create_new<::message::key>();
//
//            pkey->m_oswindow = this;
//
//            pkey->m_pwindow = this;
//
//            pkey->m_ekey = ekey;
//
//            if(pressed == WL_KEYBOARD_KEY_STATE_PRESSED)
//            {
//
//               pkey->m_atom = e_message_key_down;
//
//               information() << "e_message_key_down";
//
//            }
//            else
//            {
//
//               pkey->m_atom = e_message_key_up;
//
//               //information() << "e_message_key_up : " << (iptr) ekey;
//
//               information() << "e_message_key_up";
//
//            }
//
//            m_puserinteractionimpl->message_handler(pkey);
//
//         }
//
//      }
//
//      ::pointer < ::windowing_gtk4::keyboard > pkeyboard = windowing()->keyboard();
//
//      if (!pkeyboard->m_pxkbstate)
//      {
//
//         return;
//
//      }
//
//      const xkb_keysym_t *syms = nullptr;
//
//      // TODO can this happen?
//      if (::xkb_state_key_get_syms(pkeyboard->m_pxkbstate, key + 8, &syms) != 1)
//      {
//
//         return;
//
//      }
//
//      if (pressed)
//      {
//
//         char text[8];
//
//         auto size = ::xkb_keysym_to_utf8(syms[0], text, sizeof text);
//
//         if (size > 0)
//         {
//
//            text[size] = 0;
//
//            //Wayland_data_device_set_serial(input->data_device, serial);
//
//            auto pkey = __create_new<::message::key>();
//
//            pkey->m_oswindow = this;
//
//            pkey->m_pwindow = this;
//
//            pkey->m_atom = e_message_text_composition;
//
//            pkey->m_strText = text;
//
//            information() << "e_message_text_composition";
//
//            m_puserinteractionimpl->message_handler(pkey);
//
//         }
//
//      }
//
//   }
//
//
//   void window::__handle_keyboard_modifiers(::wl_keyboard *keyboard, uint32_t serial, uint32_t mods_depressed, uint32_t mods_latched, uint32_t mods_locked, uint32_t group)
//   {
//
//      ::pointer < ::windowing_gtk4::keyboard > pkeyboard = windowing()->keyboard();
//
//      if (!pkeyboard->m_pxkbstate)
//      {
//
//         return;
//
//      }
//
//      ::xkb_state_update_mask(pkeyboard->m_pxkbstate, mods_depressed, mods_latched, mods_locked, 0, 0, group);
//
//   }


void window::_on_windowing_close_window()
{
   ::windowing::window::_on_windowing_close_window();
}


// ::particle * window::get_interface_client_particle() // m_puserinteractionimpl->m_puserinteraction
// {
//
//    if(::is_null(m_puserinteractionimpl))
//    {
//
//       return nullptr;
//
//    }
//
//    return m_puserinteractionimpl->m_puserinteraction;
//
// }
//virtual void set_window_width(::i32 iWidth) = 0; // m_sizeWindow.cx()
//virtual void set_window_height(::i32 iHeight) = 0; // m_sizeWindow.cy()
//virtual ::size_i32 get_window_size() = 0; // m_sizeWindow
// void window::set_interface_client_size(const ::size_i32 & sizeWindow) // set_size
// {
//
//    m_puserinteractionimpl->m_puserinteraction->set_size(sizeWindow);
//
// }
//
//
// bool window::is_window_stored_iconic() // m_puserinteractionimpl->m_puserinteraction->const_layout().window().display() == e_display_iconic
// {
//
//    return m_puserinteractionimpl->m_puserinteraction->const_layout().window().display() == e_display_iconic;
//
// }
//
//
// void window::window_maximize() // m_puserinteractionimpl->m_puserinteraction->display(::e_display_zoomed);
// {
//
//    m_puserinteractionimpl->m_puserinteraction->display(::e_display_zoomed);
//
// }
//
//
// void window::window_full_screen() // m_puserinteractionimpl->m_puserinteraction->display(::e_display_full_screen);
// {
//
//    m_puserinteractionimpl->m_puserinteraction->display(::e_display_full_screen);
//
// }
//
//
// void window::window_restore() // m_puserinteractionimpl->m_puserinteraction->display(::e_display_normal);
// {
//
//    m_puserinteractionimpl->m_puserinteraction->display(::e_display_normal);
//
// }
//


void window::window_restore()
{
   main_post([this]()
             {
   if (gtk_window_is_maximized(GTK_WINDOW(m_pgtkwidget)))
   {
      gtk_window_unmaximize(GTK_WINDOW(m_pgtkwidget));
   }
             });
}


   void window::window_minimize()
   {

      main_post([this]()
    {
     // Get the GdkSurface of the window
     GdkSurface *surface = gtk_native_get_surface(GTK_NATIVE(m_pgtkwidget));

     // Get the GdkToplevel interface
     GdkToplevel *toplevel = GDK_TOPLEVEL(surface);

     // Minimize the window (iconify it)
     gdk_toplevel_minimize(toplevel);

  });

   }


void window::window_maximize()
{
   main_post([this]()
       {
  gtk_window_maximize(GTK_WINDOW(m_pgtkwidget));

});
}


   // string _gtk_get_resize_cursor_name(enum_window_edge eedge)
   // {
   //    const char * pszCursorName ;
   //    switch(eedge)
   //    {
   //       case e_window_edge_south:              pszCursorName = "s-resize"    ; break;
   //       case e_window_edge_south_west:         pszCursorName = "sw-resize"   ; break;
   //       case e_window_edge_south_east:         pszCursorName = "se-resize"   ; break;
   //       case e_window_edge_west:               pszCursorName = "w-resize"    ; break;
   //       case e_window_edge_east:               pszCursorName = "e-resize"    ; break;
   //       case e_window_edge_north_west:         pszCursorName = "nw-resize"   ; break;
   //       case e_window_edge_north_east:         pszCursorName = "ne-resize"   ; break;
   //       case e_window_edge_north:              pszCursorName = "n-resize"    ; break;
   //       default:                               pszCursorName = ""            ; break;
   //
   //    }
   //
   //    return pszCursorName;
   //
   // }


   void window::_set_cursor_from_name(const ::scoped_string & scopedstr)
   {
      ::string strCursorName(scopedstr);

      main_post([this, strCursorName]()
    {

     if (strCursorName.has_char())
     {

        gtk_widget_set_cursor_from_name(m_pgtkwidget, strCursorName);

        //        g_object_unref(cursor);
     }
     else
     {

        gtk_widget_set_cursor_from_name(m_pgtkwidget, "default");
     }

  });

   }




   // void window::_unlocked_defer_start_resize(enum_window_edge eedge, GtkGestureClick * pclick, double x, double y)
   // {
   //
   //
   // }


   ::rectangle_i32 window::_unlocked_defer_get_window_rectangle()
   {

      Window   xw = GDK_SURFACE_XID (GDK_SURFACE (gtk_native_get_surface(GTK_NATIVE (m_pgtkwidget))));

      if(xw)
      {

         Display *xd = GDK_SURFACE_XDISPLAY (GDK_SURFACE (gtk_native_get_surface(GTK_NATIVE (m_pgtkwidget))));

         if(xd)
         {

            XWindowAttributes attrs{};

            XGetWindowAttributes(xd, xw, &attrs);

            ::rectangle_i32 r;

            r.left()  = attrs.x;
            r.top()  = attrs.y;
            r.right()  = attrs.x + attrs.width;
            r.bottom()  = attrs.y + attrs.height;

         }

      }

      return {};

   }


   void window::_unlocked_defer_set_window_position(const ::point_i32 & point)
   {

      Window   xw = GDK_SURFACE_XID (GDK_SURFACE (gtk_native_get_surface(GTK_NATIVE (m_pgtkwidget))));

      if(xw)
      {

         Display *xd = GDK_SURFACE_XDISPLAY (GDK_SURFACE (gtk_native_get_surface(GTK_NATIVE (m_pgtkwidget))));

         if(xd)
         {

            XMoveWindow (xd, xw, (int)point.x(), (int)point.y());

         }

      }

   }


   void window::_unlocked_defer_set_window_position(const ::point_i32 & point, const ::size_i32 & size)
   {

      Window   xw = GDK_SURFACE_XID (GDK_SURFACE (gtk_native_get_surface(GTK_NATIVE (m_pgtkwidget))));

      if(xw)
      {

         Display *xd = GDK_SURFACE_XDISPLAY (GDK_SURFACE (gtk_native_get_surface(GTK_NATIVE (m_pgtkwidget))));

         if(xd)
         {

            XMoveResizeWindow(xd, xw, (int)point.x(), (int)point.y(), (int) size.cx(), (int) size.cy());

         }

      }

   }


   void window::_unlocked_defer_set_window_size(const ::size_i32 & size)
   {

      Window   xw = GDK_SURFACE_XID (GDK_SURFACE (gtk_native_get_surface(GTK_NATIVE (m_pgtkwidget))));

      if(xw)
      {
         Display *xd = GDK_SURFACE_XDISPLAY (GDK_SURFACE (gtk_native_get_surface(GTK_NATIVE (m_pgtkwidget))));

         if(xd)
         {
            XResizeWindow(xd, xw, (int)size.cx(), (int)size.cy());
         }
      }

   }


} // namespace windowing_gtk4



