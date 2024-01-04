find_package(Boost REQUIRED)

add_executable(Timer.1)
target_sources(Timer.1 PRIVATE Timer/1.cc)
target_link_libraries(Timer.1 PRIVATE my_config Boost::system)

add_executable(Timer.2)
target_sources(Timer.2 PRIVATE Timer/2.cc)
target_link_libraries(Timer.2 PRIVATE my_config Boost::system)

add_executable(Timer.3)
target_sources(Timer.3 PRIVATE Timer/3.cc)
target_link_libraries(Timer.3 PRIVATE my_config Boost::system)

add_executable(Timer.4)
target_sources(Timer.4 PRIVATE Timer/4.cc)
target_link_libraries(Timer.4 PRIVATE my_config Boost::system)

add_executable(Timer.5)
target_sources(Timer.5 PRIVATE Timer/5.cc)
target_link_libraries(Timer.5 PRIVATE my_config Boost::system)
