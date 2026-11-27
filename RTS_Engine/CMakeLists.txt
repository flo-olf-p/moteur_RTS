find_package(Qt6 REQUIRED COMPONENTS Core Gui Widgets)
qt_standard_project_setup()

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)

set(PROJECT_SOURCES
    main.cpp
    CAnimal.h
    CAnimal.cpp
    CRabbit.h
    CRabbit.cpp
    CWolf.h
    CWolf.cpp
    RTS_Engine.ui
    RTS_Engine.h
    RTS_Engine.cpp
    QtWidgetsDebugMenu.cpp
    QtWidgetsDebugMenu.h
    QtWidgetsDebugMenu.ui
    QtWidgetsSimulation.cpp
    QtWidgetsSimulation.h
    QtWidgetsSimulation.ui
)

qt_add_executable(${PROJECT_NAME} ${PROJECT_SOURCES})

set_target_properties(${PROJECT_NAME}
    PROPERTIES
        WIN32_EXECUTABLE TRUE
)

target_link_libraries(${PROJECT_NAME} PRIVATE Qt6::Core Qt6::Gui Qt6::Widgets)

