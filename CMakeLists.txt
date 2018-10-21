file(GLOB dirs ./ *)

foreach(tmp ${dirs})
    if(IS_DIRECTORY ${tmp})
        if(EXISTS ${tmp}/CMakeLists.txt)
            add_subdirectory(${tmp}) 
        endif()
    endif()
endforeach()
