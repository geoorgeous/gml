# GML | George's Math Library

![version](https://img.shields.io/badge/version-1.0b-blue.svg?maxAge=2592000)

[API Documentation](https://george-mcdonagh.github.io/gml/documentation/html/index.html).

GML was written to solidify my personal understanding in 3D mathematics and to assist me in writing 3D graphics applications. Though this is a pet project of mine I am developing and managing this library with the idea that others might use it. It's important to me that GML is relatively light-weight, has a well documented API, and is easy and intuitive to use and integrate in to your own projects.

GML is a statically linked library. Simply include the headers somewhere in your project and link against `gml.lib` and you're good to go! Pre-compiled binaries of the latest version of GML can be found in [bin/](https://github.com/george-mcdonagh/gml/tree/master/bin).

# Functionality

In short, GML supports **Vectors, Matrices, Quaternions, 3D Transformations, Camera transformations, and 2D + 3D Shapes with intersection checking**.

## Vectors

GML has three main Vector types, namely `Vector2`, `Vector3`, and `Vector4`. These represent floating-point mathematical Vectors with two, three, and four components respectively. For Vectors of a different type and/or size, GML has a struct template `Vector<Type, Size>`. All four Vectors have the following functionality:
 - Magnitude
 - Squared magnitude
 - Dot product multiplication against another Vector of the same type and size
 - Calculate the Vector's unit normal
 - Calculate the vector's inverse
 - Normalise the Vector
 - Limit the Vector's magnitude
 - Vector-Vector component-wise addition
 - Vector-Vector component-wise subtraction
 - Vector-Vector component-wise multiplication
 - Vector-Vector component-wise division
 - Vector-scalar multiplication
 - Vector-scalar division
 - Vector-Vector equivalence comparison
 
The following functionality is exclusive to `Vector2` and `Vector3`:
 - Calculate the angle between two Vectors
 - Calculate the distance between two Vectors
  
And finally, `Vector3` is the only Vector type that has a cross product function.

As it is quite common to use integer-based Vectors in games programming, `Vector2i`, `Vector3i`, and `Vector4i` `typedef`s are     included in the main header file for the Vector types "vectors.hpp".

## Matrices

The support for Matrices in GML is very similar to Vector support, in that there are four main types: three main types and a struct template for added flexibility. `Matrix2`, `Matrix3`, and `Matrix4` are the three non-template structs which represent floating-point square matrices of size two, three, and four respectively. For non-square matrices of different types GML has a `Matrix` struct template. The following functionality is shared by all four Matrix types:
 - Calculate the transpose of the Matrix
 - Calculate the matrix of minors of the Matrix
 - Calculate the cofactor of the Matrix
 - Calculate the adjoint matrix of the Matrix
 - Calculate the inverse matrix of the Matrix
 - Determinant
 - Matrix multiplication
 - Matrix-Matrix component-wise addition
 - Matrix-Matrix component-wise subtraction
 - Matrix-scalar multiplication
 - Matrix-scalar division
 - Vector-Vector equivalence comparison
 
## Quaternions and Rotations
 
Quaternions are largely used in game development to represent rotations. The GML API provides the following functionality in relation to Quaternions and related rotation-based usage:
  - Quaternion conjugate
  - Quaternion normalisation
  - Extract the XYZ rotation angles from a quaternion
  - Construct a Quaternion given XYZ rotation angles
  - Construct a Quaternion given an axis of rotation and an angle
  - Construct a rotation Matrix transformation from a Quaternion
 
## 3D Transformations
 
The `Transform` class represents a 3D transformation in position, scale, and rotation. As well as this there is a "transformations.hpp" file which includes a bunch of functions to help with creation transformation matrices. These transform functions include: translation, scale, rotation (from quaternion), and rotation around the x-axis, y-axis, and z-axis.

GML also includes perspective, orthographic, view, and look-at matrix construction functions for all your camera-related needs!
  
## Shapes
  
The GML library has a collection of simple 2D and 3D shape structs, along with intersection checking between any pair of them (provided they are in the same spacial dimension). The following shape structs are currently implemented:
 - `Point2D`
 - `Line2D`
 - `Circle`
 - `Rect`
 - `Point3D`
 - `Line3D`
 - `Sphere`
 - `Cuboid`
 
[API Documentation](https://george-mcdonagh.github.io/gml/documentation/html/index.html).
