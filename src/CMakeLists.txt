file(GLOB task_sources RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} */main.cpp)

foreach(main_file ${task_sources})
    get_filename_component(dir ${main_file} DIRECTORY)
    add_executable(task_${dir} ${main_file})
endforeach()
