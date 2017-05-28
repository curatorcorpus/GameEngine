CMAKE_MINIMUM_REQUIRED(VERSION 2.6)

PROJECT(render_engine)

SET(src_code
	
	render_engine.cpp
)

ADD_EXECUTABLE(render_engine
	${src_code}
)