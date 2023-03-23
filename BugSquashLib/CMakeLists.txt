project(BugSquashLib)

set(SOURCE_FILES MainFrame.cpp MainFrame.h BugSquashView.cpp BugSquashView.h Item.cpp Item.h Bug.cpp Bug.h BugSquash.cpp BugSquash.h Scoreboard.cpp Scoreboard.h Level.cpp Level.h ids.h ItemVisitor.cpp ItemVisitor.h BugNull.cpp BugNull.h BugRedundancy.cpp BugRedundancy.h BugGarbage.cpp BugGarbage.h FatGarbageBug.cpp FatGarbageBug.h FatNullBug.cpp FatNullBug.h Feature.cpp Feature.h Program.cpp Program.h Code.cpp Code.h SimpleBugSquashVisitor.cpp SimpleBugSquashVisitor.h FatBugSquashVisitor.cpp FatBugSquashVisitor.h CodeDlg.cpp CodeDlg.h BugStateVisitor.cpp BugStateVisitor.h BugNuke.cpp BugNuke.h Images.cpp Images.h SquashCheckVisitor.cpp SquashCheckVisitor.h SquashCheckVisitor.cpp BugNukeVisitor.cpp BugNukeVisitor.h)

set(wxBUILD_PRECOMP OFF )
find_package(wxWidgets COMPONENTS core base xrc html xml REQUIRED)

include(${wxWidgets_USE_FILE})

add_library(${PROJECT_NAME} STATIC ${SOURCE_FILES})

target_link_libraries(${PROJECT_NAME} ${wxWidgets_LIBRARIES})

# pch will be a precompiled library so it won't be compiled more than once
target_precompile_headers(${PROJECT_NAME} PRIVATE pch.h)
