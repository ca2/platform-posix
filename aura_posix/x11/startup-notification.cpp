//
// Created by camilo on 17/04/22. 03:36 <3ThomasBorregaardSørensen!!
//
//
// Created by camilo on 17/02/2021. 00:32 BRT <3TBS_!!
//
#include "framework.h"
#include "startup-notification.h"
#include "windowing.h"
#include "acme/platform/application.h"
#include "acme/platform/context.h"
#ifdef WITH_SN
#define SN_API_NOT_YET_FROZEN
#include <libsn/sn.h>
#include "_x11.h"
#include "aura/windowing/display.h"

extern int g_iIgnoreXDisplayError;


void on_sn_launch_context(void * pSnContext , Window window)
{

   SnLauncheeContext * pcontext = (SnLauncheeContext *) pSnContext;

   sn_launchee_context_setup_window(pcontext, window);

}


void on_sn_launch_complete(void * pSnContext)
{

   SnLauncheeContext * pcontext = (SnLauncheeContext *) pSnContext;

   sn_launchee_context_complete(pcontext);

}


void x_display_error_trap_push(SnDisplay * sndisplay, Display * display)
{

   g_iIgnoreXDisplayError++;

}


void x_display_error_trap_pop(SnDisplay * sndisplay, Display * display)
{

   //synchronous_lock sl(user_synchronization());

   g_iIgnoreXDisplayError--;

   if(g_iIgnoreXDisplayError == 0)
   {

      XSync(display, false);

   }

}


namespace windowing_posix
{


   void windowing::_libsn_start_context()
   {

      Display * pdisplay = (Display *) display()->_m_pX11Display;

      SnDisplay * psndisplay = sn_display_new(pdisplay, &x_display_error_trap_push, &x_display_error_trap_pop);

      int iScreen = DefaultScreen(pdisplay);

      auto papp = acmeapplication();

      string strWMClass = papp->m_strAppId;

      strWMClass.find_replace("/", ".");

      m_pSnLauncheeContext = sn_launchee_context_new(psndisplay, iScreen, strWMClass);

   }


} // namespace windowing_posix


#endif



