# 3D Ray Tracer
Created with the Guidance of Ray Tracer Challenge : A Test-driven Guide to Your First 3d Renderer created by Jamis Buck. Created a 3D raytracer in C++ in a test driven approach. Incorporates features such as: lighting.
## Chapter 1: Tuples, Points, and Vectors

![image](https://github.com/user-attachments/assets/e3f841d1-cf96-4f45-93a7-8d1a8d7e29de)

Created a custom tuple base class which will be useful in creating vectors, points, and later on colors. This has a lot of different operator overloading functions for creating new vectors and points, as  well as getting their dot products, cross products, magnitude, and normalization.

## Chapter 2: Drawing on a Canvas

![image](https://github.com/user-attachments/assets/a9834704-d692-422d-88a5-3d990a44d4a6)

This would be the first generated image of my raytracer. As you can see it is very barebones and I was able to take the data and implement it as a ppm file that I can open on gimp. The way this image was constructed was using a custom created projectile and environment structs that is passed into a tick function to demonstrate movement with certain wind and gravity options. ALso created a custom color class which inherits from our tuple class so that we may represent color as r, g, b, w values on our canvas.

## Chapter 3: Matrices

![image](https://github.com/user-attachments/assets/bbc57dac-a821-4fb3-a731-d18856fabec1)

This was created so that we can use later for transformations on our tuple types. Features creation of a matrix4, matrix3, and matrix2 classes with custom math functions such as finding the identity matrix, finding the inverse, the submatrix, the minor, the cofactor, the determinant, and it's transposition. Also adds some additionaly functions for aiding in visualizing the creation and implementations.

## Chapter 4: Matrix Transformations

![image](https://github.com/user-attachments/assets/70e51873-ea0a-4252-bdea-98b60c9e7e2a)

This chapter is largely about taking our created matrix classes and creating different math functions that we can apply to them. This chapter largely focused on using our previously created operator overloading functions, as well as functions for translating, scaling, rotating, and shearing a matrix. The result of these transformations will usually return another point or a different vector.

## Chapter 5: Ray-Sphere Intersections

![image](https://github.com/user-attachments/assets/3c5eddd1-37ab-48fc-8255-440e258802f8)

The bane of my existence. Will definitely need a hard earned break after this one, need to redo my documentation for all the previous sections. I was having many errors with pointers and references here I believe. The primary focus of this section was to exhibit intersections between a ray and a sphere and drawing out a sort of shadow of our 3D object. Drawn on a 400x400 canvas, anything more was past my patience.

![image](https://github.com/user-attachments/assets/bcb1f6d3-c331-4da9-8e44-c460f4174be8)

At least my matrix transformations were perfectly fine!

## Chapter 6: Light and Shading



Now we're getting to the more interesting bits! In this section we implemented the Phong Reflection Model to simulate lighting and shading to our object. We also created separate world and object spaces to allow for proper transformation and lighting techniques. Using the Phong Reflection Model the interaction is simulated via Ambient reflection which is just background lighting (or light reflected from other objects in the environment), Diffuse reflection is light reflected from a matte surface which depends only on the angle between the light source and the surface normal, and finally Specular reflection which is the reflection of the light source itself and results in what is called a specular highlight (the little bright white spot you'll see on your object). The way this new code works is that using a new material and point light data structure I was able to generate a new color pixel by pixel based on the material, the light, the position of the intersection point, the eye direction, and the normal at the intersection point. Based on each pixel it'll return a color per pixel based on our lighting function. Since we created our material class, we can assign several values such the ambient, the color, the diffuse, the specular, and it's shininess and then based on that value as well as the position of the camera, the position of the light and some other things we output an image.
