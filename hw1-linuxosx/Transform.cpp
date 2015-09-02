// Transform.cpp: implementation of the Transform class.


#include "Transform.h"

//Please implement the following functions:

// Helper rotation function.  
mat3 Transform::rotate(const float degrees, const vec3& axis) {
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
  
  return mat3(m11,m21,m31,m12,m22,m32,m13,m23,m33);
}

// Transforms the camera left around the "crystal ball" interface
void Transform::left(float degrees, vec3& eye, vec3& up) {
  mat3 matrix_rotation = rotate(degrees,up) ;
  eye = matrix_rotation * eye ; 
}

// Transforms the camera up around the "crystal ball" interface
void Transform::up(float degrees, vec3& eye, vec3& up) {
  vec3 axis = glm::cross(eye,up) ;
  vec3 axis_norm = glm::normalize(axis);
  mat3 matrix_rotation = rotate(degrees,axis_norm) ;
  eye = matrix_rotation * eye ;
  up = matrix_rotation * up ;
}

// Your implementation of the glm::lookAt matrix
mat4 Transform::lookAt(vec3 eye, vec3 up) {
  vec3 w = glm::normalize(eye) ;
  vec3 bcrossw = glm::cross(up,w) ;
  vec3 u = glm::normalize(bcrossw) ;
  vec3 v = glm::cross(w,u) ;
  // You will change this return call
  
  return mat4(u.x,v.x,w.x,0.,u.y,v.y,w.y,0.,u.z,v.z,w.z,0.,-(u.x*eye.x + u.y*eye.y + u.z*eye.z),-(v.x*eye.x + v.y*eye.y + v.z*eye.z),-(w.x*eye.x + w.y*eye.y + w.z*eye.z),1.);
}

Transform::Transform()
{

}

Transform::~Transform()
{

}
