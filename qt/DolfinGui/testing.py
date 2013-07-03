from PythonQt import *


geometryOperatorBox.title = 'Hello!'

def changeTitle():
	geometryOperatorBox.title = formulaBar.text

titleButton.connect('clicked()', changeTitle)
#formulaBar.connect('returnPressed()', changeTitle)