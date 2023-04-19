cmake_minimum_required(VERSION 3.5)

project(untitled VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)





find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets)

set(PROJECT_SOURCES
        main.cpp
        mainwindow.cpp
        mainwindow.h
        mainwindow.ui
        Interprete/Contexto/Tipos/t_tipos.h Interprete/Contexto/Tipos/t_tipos.cpp
        Interprete/Contexto/Tipos/tipo.h Interprete/Contexto/Tipos/tipo.cpp
        Interprete/Contexto/Simbolos/memoria.h Interprete/Contexto/Simbolos/memoria.cpp
        Interprete/Contexto/Simbolos/simbolo.h Interprete/Contexto/Simbolos/simbolo.cpp
        AST/abstractexpr.h AST/abstractexpr.cpp
        Interprete/Contexto/contexto.h Interprete/Contexto/contexto.cpp
        Interprete/Contexto/resultado.h Interprete/Contexto/resultado.cpp
        AST/No_Terminales/nt_lsentencias.h AST/No_Terminales/nt_lsentencias.cpp
        AST/No_Terminales/nt_bloque.h AST/No_Terminales/nt_bloque.cpp
        AST/No_Terminales/nt_asigvar.h AST/No_Terminales/nt_asigvar.cpp
        AST/No_Terminales/nt_declvar.h AST/No_Terminales/nt_declvar.cpp
        AST/No_Terminales/nt_imprimir.h AST/No_Terminales/nt_imprimir.cpp
        AST/No_Terminales/nt_listaexpr.h AST/No_Terminales/nt_listaexpr.cpp
        AST/No_Terminales/nt_s.h AST/No_Terminales/nt_s.cpp
        AST/No_Terminales/nt_tipo.h AST/No_Terminales/nt_tipo.cpp
        AST/No_Terminales/nt_sentencia.h AST/No_Terminales/nt_sentencia.cpp
        AST/Terminales/t_id.h AST/Terminales/t_id.cpp
        AST/Terminales/t_numero.h AST/Terminales/t_numero.cpp
        AST/Terminales/t_string.h AST/Terminales/t_string.cpp
        Parser/interfaz.h Parser/interfaz.cpp
        Parser/parser.cpp Parser/parser.hpp
        Parser/location.hh Parser/stack.hh
        Parser/position.hh Parser/lex.yy.c
        Parser/Parser.y Parser/Lexer.l
        AST/No_Terminales/Expresiones/nt_id.h AST/No_Terminales/Expresiones/nt_id.cpp
        AST/No_Terminales/Expresiones/nt_negacion.h AST/No_Terminales/Expresiones/nt_negacion.cpp
        AST/No_Terminales/Expresiones/nt_suma.h AST/No_Terminales/Expresiones/nt_suma.cpp
        AST/No_Terminales/Expresiones/nt_multiplicacion.h AST/No_Terminales/Expresiones/nt_multiplicacion.cpp
        AST/No_Terminales/Expresiones/nt_resta.h AST/No_Terminales/Expresiones/nt_resta.cpp
        AST/No_Terminales/Expresiones/nt_division.h AST/No_Terminales/Expresiones/nt_division.cpp
        AST/No_Terminales/Expresiones/nt_exponencial.h AST/No_Terminales/Expresiones/nt_exponencial.cpp
        AST/Terminales/t_float.h AST/Terminales/t_float.cpp
        AST/No_Terminales/Expresiones/nt_mayor.h AST/No_Terminales/Expresiones/nt_mayor.cpp
        AST/No_Terminales/Expresiones/nt_menor.h AST/No_Terminales/Expresiones/nt_menor.cpp
        AST/No_Terminales/Expresiones/nt_menorigual.h AST/No_Terminales/Expresiones/nt_menorigual.cpp
        AST/No_Terminales/Expresiones/nt_mayorigual.h AST/No_Terminales/Expresiones/nt_mayorigual.cpp
        AST/No_Terminales/Expresiones/nt_igualigual.h AST/No_Terminales/Expresiones/nt_igualigual.cpp
        AST/No_Terminales/Expresiones/nt_diferente.h AST/No_Terminales/Expresiones/nt_diferente.cpp
        AST/No_Terminales/Expresiones/nt_or.h AST/No_Terminales/Expresiones/nt_or.cpp
        AST/No_Terminales/Expresiones/nt_and.h AST/No_Terminales/Expresiones/nt_and.cpp
        AST/No_Terminales/Expresiones/nt_not.h AST/No_Terminales/Expresiones/nt_not.cpp
        AST/No_Terminales/nt_declvector.h AST/No_Terminales/nt_declvector.cpp
        AST/No_Terminales/nt_assignvector.h AST/No_Terminales/nt_assignvector.cpp
        Interprete/Contexto/environment.h Interprete/Contexto/environment.cpp
        Interprete/Contexto/environmentfunc.h Interprete/Contexto/environmentfunc.cpp
        AST/Terminales/t_boolean.h AST/Terminales/t_boolean.cpp
        AST/No_Terminales/nt_escape.h AST/No_Terminales/nt_escape.cpp
        AST/No_Terminales/Expresiones/nt_modulo.h AST/No_Terminales/Expresiones/nt_modulo.cpp
        AST/No_Terminales/nt_declfunc.h AST/No_Terminales/nt_declfunc.cpp
        AST/No_Terminales/nt_llamada.h AST/No_Terminales/nt_llamada.cpp




)

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(untitled
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES}
    )
# Define target properties for Android with Qt 6 as:
#    set_property(TARGET untitled APPEND PROPERTY QT_ANDROID_PACKAGE_SOURCE_DIR
#                 ${CMAKE_CURRENT_SOURCE_DIR}/android)
# For more information, see https://doc.qt.io/qt-6/qt-add-executable.html#target-creation
else()
    if(ANDROID)
        add_library(untitled SHARED
            ${PROJECT_SOURCES}
        )
# Define properties for Android with Qt 5 after find_package() calls as:
#    set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android")
    else()
        add_executable(untitled
            ${PROJECT_SOURCES}
        )
    endif()
endif()

target_link_libraries(untitled PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)

set_target_properties(untitled PROPERTIES
    MACOSX_BUNDLE_GUI_IDENTIFIER my.example.com
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

install(TARGETS untitled
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(untitled)
endif()
