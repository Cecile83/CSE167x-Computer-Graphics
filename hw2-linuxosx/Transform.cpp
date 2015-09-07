// Transform.cpp: implementation of the Transform class.

// Note: when you construct a matrix using mat4() or mat3(), it will be COLUMN-MAJOR
// Keep this in mind in readfile.cpp and display.cpp
// See FAQ for more details or if you're having problems.

#include "Transform.h"

// Helper rotation function.  Please implement this.  
mat3 Transform::rotate(const float degrees, const vec3& axis) 
{
  mat3 ret;
  float angle = degrees * pi / 180. ;
  float x, y, z ; 
  float m11, m12, m13, m21, m22, m23, m31, m32, m33 ;
  
  x = axis[0];
  y = axis[1];
  z = axis[2];
  
  m11 = cos(angle) + (1-cos(angle)) * pow(x,2) ;
  m12 = (1-cos(angle)) * x * y - z * sin(angle) ;
  m13 = (1-cos(angle)) * x * z + y * sin(angle) ;
  m21 = (1-cos(angle)) * x * y + z * sin(angle) ;
  m22 = cos(angle) + (1-cos(angle)) * pow(y,2) ;
  m23 = (1-cos(angle)) * y * z - x * sin(angle) ;
  m31 = (1-cos(angle)) * x * z - y * sin(angle) ;
  m32 = (1-cos(angle)) * y * z + x * sin(angle) ;
  m33 = cos(angle) + (1-cos(angle)) * pow(z,2) ;
  
  ret=mat3(m11,m21,m31,m12,m22,m32,m13,m23,m33);
  
  return ret;
}

void Transform::left(float degrees, vec3& eye, vec3& up) 
{
  mat3 matrix_rotation = rotate(degrees,up) ;
  eye = matrix_rotation * eye ;  
}

void Transform::up(float degrees, vec3& eye, vec3& up) 
{
  vec3 axis = glm::cross(eye,up) ;
  vec3 axis_norm = glm::normalize(axis);
  mat3 matrix_rotation = rotate(degrees,axis_norm) ;
  eye = matrix_rotation * eye ;
  up = matrix_rotation * up ;  
}

mat4 Transform::lookAt(const vec3 &eye, const vec3 &center, const vec3 &up) 
{
  mat4 ret;
  vec3 w = glm::normalize(eye) ;
  vec3 bcrossw = glm::cross(up,w) ;
  vec3 u = glm::normalize(bcrossw) ;
  vec3 v = glm::cross(w,u) ;
  // You will change this return call
  
  ret = mat4(u.x,v.x,w.x,0.,u.y,v.y,w.y,0.,u.z,v.z,w.z,0.,-(u.x*eye.x + u.y*eye.y + u.z*eye.z),-(v.x*eye.x + v.y*eye.y + v.z*eye.z),-(w.x*eye.x + w.y*eye.y + w.z*eye.z),1.);

  return ret;
}

mat4 Transform::perspective(float fovy, float aspect, float zNear, float zFar)
{
  mat4 ret;
  // YOUR CODE FOR HW2 HERE
  // New, to implement the perspective transform as well.  
  return ret;
}

mat4 Transform::scale(const float &sx, const float &sy, const float &sz) 
{
  mat4 ret;
  // YOUR CODE FOR HW2 HERE
  // Implement scaling 
  return ret;
}

mat4 Transform::translate(const float &tx, const float &ty, const float &tz) 
{
  mat4 ret;
  // YOUR CODE FOR HW2 HERE
  // Implement translation 
  return ret;
}

// To normalize the up direction and construct a coordinate frame.  
// As discussed in the lecture.  May be relevant to create a properly 
// orthogonal and normalized up. 
// This function is provided as a helper, in case you want to use it. 
// Using this function (in readfile.cpp or display.cpp) is optional.  

vec3 Transform::upvector(const vec3 &up, const vec3 & zvec) 
{
  vec3 x = glm::cross(up,zvec); 
  vec3 y = glm::cross(zvec,x); 
  vec3 ret = glm::normalize(y); 
  return ret; 
}


Transform::Transform()
{

}

Transform::~Transform()
{

}
