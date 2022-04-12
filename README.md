CPSC 4050 Project Synopsis
Team members:
Armando Partida-Sanabia, 
David Brown
Project Goal:
The goal of the project is to render a room scene. The room will contain several standard objects you would expect to see in a bedroom, such as a bed, a nightstand, a dresser, etc. This room is going to be lit from a single point (window), and this will be applied to all of the objects. Focal point will be the center of the room, and you can look around using the camera.
The room will contain:
1 Window
4 Walls
1 Floor
1 Ceiling
1 Bed
1 Nightstand
1 Lamp
1 Dresser
1 Computer Screen
1 Desk
Motivation/Expected learning:
The motivation for this is to render a full scene using the knowledge we’ve gained regarding object creation and placement. We expect to learn about lighting, transparent objects (window), and how to apply textures to some objects.
Project Description:
Rendering
We plan to render all of our generated meshes by using OpenGL calls and transform the meshes using translation matrices to place them in our world coordinate system. We will also use GLUT to register our display callback function to handle all of our rendering.
Mesh generation
We plan to generate various meshes representing common items in a bedroom, such as a bed, lamp, etc. Each object will have its own class to generate custom geometry and render them in our program.
Lighting/shading
Some of our objects will have emission(like the lamp) or transparency(window). We will use OpenGL calls to implement lights and make objects react to these lights with shading.
Expected Results/Functionality:
The end product is to be a room with the camera fixated in the center. The camera can rotate around in a realistic way (X and Z, maybe), so the room can be inspected. The objects will have lighting coming from a singular origin point, and some objects will be textured. 
Tools Used:
We plan to implement our project using C++, GLUT and OpenGL functions
Challenges to be expected:
Some possible challenges include maintaining the mesh transformations, creating the program foundation to handle rendering custom objects and lighting.
