project(BugSquashLib)

set(SOURCE_FILES MainFrame.cpp MainFrame.h BugSquashView.cpp BugSquashView.h Item.cpp Item.h Bug.cpp Bug.h BugSquash.cpp BugSquash.h Scoreboard.cpp Scoreboard.h Level.cpp Level.h ids.h ItemVisitor.cpp ItemVisitor.h)

set(wxBUILD_PRECOMP OFF )
find_package(wxWidgets COMPONENTS core base xrc html xml REQUIRED)

include(${wxWidgets_USE_FILE})

add_library(${PROJECT_NAME} STATIC ${SOURCE_FILES})

target_link_libraries(${PROJECT_NAME} ${wxWidgets_LIBRARIES})

# pch will be a precompiled library so it won't be compiled more than once
target_precompile_headers(${PROJECT_NAME} PRIVATE pch.h)