project(QuestLib_v2)

add_library(QuestLib_v2 STATIC
    src/Reward_v2.cpp
    src/QuestTimer_v2.cpp
    src/SubQuest_v2.cpp
    src/Quest_v2.cpp
    src/questFunctions_v2.cpp
)

target_include_directories(QuestLib_v2
    PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/include
        ${CMAKE_SOURCE_DIR}/include
)

target_compile_features(QuestLib_v2 PUBLIC cxx_std_17)

