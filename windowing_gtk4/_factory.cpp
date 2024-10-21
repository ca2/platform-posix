#include "framework.h"
#include "text_composition_client.h"
#include "buffer.h"
#include "display.h"
#include "window.h"
#include "windowing.h"
#include "text_composition_client.h"
#include "icon.h"
#include "cursor.h"
#include "keyboard.h"
#include "aura/windowing/monitor.h"


//__FACTORY_EXPORT void nano_user_wayland_factory(::factory::factory * pfactory);

__FACTORY_EXPORT void windowing_gtk4_factory(::factory::factory * pfactory)
{

   //nano_user_wayland_factory(pfactory);

   printf("windowing_gtk4 factory\n");

   pfactory->add_factory_item < ::windowing_gtk4::buffer, ::graphics::graphics > ();

   pfactory->add_factory_item < ::windowing_gtk4::display, ::acme::windowing::display > ();
   pfactory->add_factory_item < ::windowing_gtk4::window, ::acme::windowing::window > ();
   pfactory->add_factory_item < ::windowing_gtk4::windowing, ::acme::windowing::windowing > ();
   pfactory->add_factory_item < ::windowing_gtk4::text_composition_client, ::user::text_composition_client > ();

   pfactory->add_factory_item < ::windowing_gtk4::icon, ::windowing::icon > ();
   pfactory->add_factory_item < ::windowing_gtk4::cursor, ::windowing::cursor > ();
   pfactory->add_factory_item < ::windowing_gtk4::keyboard, ::windowing::keyboard > ();

   pfactory->add_factory_item < ::windowing::monitor > ();


}



