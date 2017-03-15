PROJECT(LightArtLikeRepresentation)
cmake_minimum_required(VERSION 2.7)

## 実行ファイルの出力ディレクトリの設定
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_LIST_DIR}/bin)

## ライブラリファイルの出力ディレクトリの設定
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_CURRENT_LIST_DIR}/lib)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_CURRENT_LIST_DIR}/lib)

include_directories(/usr/local/Cellar/opencv3/3.2.0/include/)
link_directories(/usr/local/Cellar/opencv3/3.2.0/lib/)

# インクルードフォルダを相対パスの検索対象に設定する
IF(WIN32)
add_definitions("/I${CMAKE_SOURCE_DIR}/src")
ELSE()
add_definitions("-I ${CMAKE_SOURCE_DIR}/src")
ENDIF()


## プロジェクトに含むソースコードのトラッキング
# includeフォルダとsrcフォルダにあるファイルのみを対象にする
FILE(GLOB_RECURSE ALL_FILES
	RELATIVE ${CMAKE_SOURCE_DIR}
 	src/*.h src/*.hpp src/*.cpp
)

## ディレクトリ構成を保持したままビルドシステムを構築するマクロ
foreach(FILE ${ALL_FILES})
  get_filename_component(PARENT_DIR "${FILE}" PATH)
  # skip src or include and changes /'s to \\'s
  string(REGEX REPLACE "(\\./)?(src|include)/?" "" GROUP "${PARENT_DIR}")
  string(REPLACE "/" "\\" GROUP "${GROUP}")

  # group into "Source Files" and "Header Files"
  set(GROUP "Source Files\\${GROUP}")

  source_group("${GROUP}" FILES "${FILE}")
endforeach()

# C++11を有効にする
add_definitions("-Wall -std=c++14")
add_executable(light_art
	${ALL_FILES}
	${IMGUI_SOURCES}
)

target_link_libraries(light_art
	opencv_core
	opencv_highgui
	opencv_imgcodecs
	opencv_imgproc
	opencv_video
	opencv_videoio
	
)