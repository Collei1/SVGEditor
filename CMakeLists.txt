cmake_minimum_required(VERSION 3.28)
project(SVGEditor)

# 基础配置
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

# 查找 Qt 库
find_package(Qt5 COMPONENTS Core Gui Widgets Svg REQUIRED)

# ==================== 文件分类 ====================
# 源文件列表
set(SOURCES
        src/main.cpp
        src/MainWindow/mainwindow.cpp
        src/CanvasFrame/canvasframe.cpp
        src/CanvasFrame/graphicsframe.cpp
        src/CanvasFrame/overlaywidget.cpp
        src/CanvasFrame/svgframe.cpp
        src/CanvasFrame/textframe.cpp
        src/AttributeManager/attributemanager.cpp
        src/AttributeManager/borderstylecombobox.cpp
        src/MenuManager/menumanager.cpp
        src/RegeditSettings/regeditsettings.cpp
)

# 头文件列表
set(HEADERS
        src/MainWindow/mainwindow.h
        src/Graphics/graphics.h
        src/CanvasFrame/canvasframe.h
        src/CanvasFrame/graphicsframe.h
        src/CanvasFrame/overlaywidget.h
        src/CanvasFrame/svgframe.h
        src/CanvasFrame/textframe.h
        src/Graphics/graphicsfactory.h
        src/Graphics/config.h
        src/AttributeManager/attributemanager.h
        src/AttributeManager/borderstylecombobox.h
        src/MenuManager/menumanager.h
        src/RegeditSettings/regeditsettings.h
        src/Command/command.h
)

# UI 文件列表
set(UI_FILES
        src/MainWindow/mainwindow.ui
)

# 资源文件
set(RESOURCES
        res.qrc
)

# ==================== 构建目标 ====================
add_executable(SVGEditor
        WIN32
        ${SOURCES}
        ${HEADERS}
        ${UI_FILES}
        ${RESOURCES}
)

# 链接 Qt 库
target_link_libraries(SVGEditor
        Qt::Core
        Qt::Gui
        Qt::Widgets
        Qt::Svg
)

# ==================== Windows 部署 ====================
if (WIN32 AND NOT DEFINED CMAKE_TOOLCHAIN_FILE)
    set(DEBUG_SUFFIX)
    if (MSVC AND CMAKE_BUILD_TYPE MATCHES "Debug")
        set(DEBUG_SUFFIX "d")
    endif ()

    # 定位 Qt 安装路径
    set(QT_INSTALL_PATH "${CMAKE_PREFIX_PATH}")
    if (NOT EXISTS "${QT_INSTALL_PATH}/bin")
        set(QT_INSTALL_PATH "${QT_INSTALL_PATH}/..")
        if (NOT EXISTS "${QT_INSTALL_PATH}/bin")
            set(QT_INSTALL_PATH "${QT_INSTALL_PATH}/..")
        endif ()
    endif ()

    # 复制平台插件
    if (EXISTS "${QT_INSTALL_PATH}/plugins/platforms/qwindows${DEBUG_SUFFIX}.dll")
        add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
                COMMAND ${CMAKE_COMMAND} -E make_directory
                "$<TARGET_FILE_DIR:${PROJECT_NAME}>/plugins/platforms/"
        )
        add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
                COMMAND ${CMAKE_COMMAND} -E copy
                "${QT_INSTALL_PATH}/plugins/platforms/qwindows${DEBUG_SUFFIX}.dll"
                "$<TARGET_FILE_DIR:${PROJECT_NAME}>/plugins/platforms/"
        )
    endif ()

    # 复制核心 DLL
    foreach (QT_LIB Core Gui Widgets Svg)
        add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
                COMMAND ${CMAKE_COMMAND} -E copy
                "${QT_INSTALL_PATH}/bin/Qt5${QT_LIB}${DEBUG_SUFFIX}.dll"
                "$<TARGET_FILE_DIR:${PROJECT_NAME}>"
        )
    endforeach (QT_LIB)
endif ()