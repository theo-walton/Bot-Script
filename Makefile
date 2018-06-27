
SETTINGNAME = setup

SCRIPTNAME = script

CPPSRC = cpp_src/*.cpp

OCSRC = m_src/*.m

SETTINGSRC = setting_dir/*.cpp

SCRIPTSRC = script_dir/*.cpp

CPPINC = -I cpp_src/.

OCINC = -I m_src/.

SETTINGINC = -I setting_dir/.

SCRIPTINC = -I script_dir/.

INTERFACE = -I interfaces/.

OBJECTS = objects/*.o

SETTINGOBJ = setting_objects/*.o

SCRIPTOBJ = script_objects/*.o

FRAMEWORKS = -framework Foundation -framework CoreGraphics -framework CoreServices -framework ImageIO

make:
	clang++ -c $(CPPSRC) $(CPPINC) $(INTERFACE)
	clang -c $(OCSRC) $(OCINC) $(INTERFACE)
	mv *.o objects
	clang++ -c $(SETTINGSRC) $(SETTINGINC) $(CPPINC) $(INTERFACE)
	mv *.o setting_objects
	clang++ -c $(SCRIPTSRC) $(SCRIPTINC) $(CPPINC) $(INTERFACE)
	mv *.o script_objects
	clang++ -o $(SETTINGNAME) $(OBJECTS) $(SETTINGOBJ) $(FRAMEWORKS) $(CPPINC) $(OCINC) $(INTERFACE)
	clang++ -o $(SCRIPTNAME) $(OBJECTS) $(SCRIPTOBJ) $(FRAMEWORKS) $(CPPINC) $(OCINC) $(INTERFACE)

fclean:
	rm -rf $(OBJECTS) $(SETTINGOBJ) $(SCRIPTOBJ)
	rm -rf $(SETTINGNAME) $(SCRIPTNAME)
