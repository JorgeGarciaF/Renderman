all: render

compile:
	shader -o bin/emboss.slo shaders/emboss.sl
	shader -o bin/plastico.slo shaders/plastico.sl

render: compile
	prman rib/naranja.rib