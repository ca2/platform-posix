

if(${LXQ_DESKTOP})
   execute_process(COMMAND $ENV{HOME}/bin/application_build_helper --lxq-release OUTPUT_VARIABLE LXQ_RELEASE_RAW OUTPUT_STRIP_TRAILING_WHITESPACE)
   message(STATUS "LXQ_RELEASE_RAW is ${LXQ_RELEASE_RAW}")
   string(TOLOWER ${LXQ_RELEASE_RAW} LXQ_RELEASE)
   string(FIND ${LXQ_RELEASE} "." LXQ_RELEASE_FIRST_DOT)
   string(SUBSTRING ${LXQ_RELEASE} 0 ${LXQ_RELEASE_FIRST_DOT} LXQ_RELEASE_MAJOR)
   message(STATUS "LXQ_RELEASE_MAJOR is ${LXQ_RELEASE_MAJOR}")
   if(${LXQ_RELEASE_MAJOR} GREATER_EQUAL "2")
      set(LXQ_RELEASE_MAJOR "2")
      set(HAS_LXQ2 TRUE)
      set(HAS_LXQ1 FALSE)
      add_compile_definitions(HAS_LXQ2)
      set(default_nano_user nano_user_lxq2)
      set(default_innate_ui innate_ui_lxq2)
   elseif(${LXQ_RELEASE_MAJOR} EQUAL "1")
      set(LXQ_RELEASE_MAJOR "1")
      set(HAS_LXQ2 FALSE)
      set(HAS_LXQ1 TRUE)
      add_compile_definitions(HAS_LXQ1)
      set(default_nano_user nano_user_lxq1)
      set(default_innate_ui innate_ui_lxq1)
   endif()
   message(STATUS "HAS_LXQ2 is ${HAS_LXQ2}")
   message(STATUS "HAS_LXQ1 is ${HAS_LXQ1}")
endif()



