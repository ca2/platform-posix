// created by Camilo 2021-01-31 05:13 BRT <3CamiloSasukeThomasBorregaardSoerensen
#pragma once


#if defined(HAS_GTK4)
#include "node_gtk4/monitor.h"
#elif defined(HAS_GTK3)
#include "node_gtk3/monitor.h"
#endif


namespace node_gtk_based
{


   class CLASS_DECL_AURA monitor :
#if defined(HAS_GTK4)
   virtual public ::node_gtk4::monitor
#elif defined(HAS_GTK3)
   virtual public ::node_gtk3::monitor
#endif
   {
   public:


      //::collection::index                                               m_iIndex;
      //::int_rectangle                                       m_rectangle;
      //::int_rectangle                                       m_rectangleWorkspace;


      monitor();
      ~monitor() override;


      //::windowing_x11::windowing * x11_windowing() const {return (::windowing_x11::windowing *) m_pdisplay->m_pwindowing->m_pWindowing; }
      //::windowing_x11::display * x11_display() const {return (::windowing_x11::display *) m_pdisplay->m_pDisplay; }



      void update_cache() override;


      unsigned int monitor_color_temperature() override;
      bool adjust_monitor( unsigned int dwTemperature, double dBrightness, double dwGamma) override;


//      virtual ::e_status get_monitor_rectangle(::int_rectangle * prectangle) override;
//      virtual ::e_status get_workspace_rectangle(::int_rectangle * prectangle) override;
//
//
//      virtual ::e_status _get_monitor_rectangle();
//      virtual ::e_status _get_workspace_rectangle();


   };


   //using monitor_map = iptr_map < ::pointer<monitor >>


} // namespace node_gtk_based



