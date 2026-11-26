# GLUT 2D Advanced Skills
Ten standalone C++/FreeGLUT examples:
1. Midpoint ellipse
2. Scanline polygon filling
3. Boundary fill (queue-based region demonstration)
4. Flood fill (queue-based region demonstration)
5. Cohen-Sutherland line clipping
6. Liang-Barsky line clipping
7. Sutherland-Hodgman polygon clipping
8. 2D transformations (scale, rotate, translate)
9. Circle collision detection
10. Mouse selection and drag-and-drop

Compile one file at a time (each has its own main):
g++ filename.cpp -o app.exe -lfreeglut -lopengl32 -lglu32

These use classic 2D immediate-mode OpenGL and FreeGLUT. No 3D content.
