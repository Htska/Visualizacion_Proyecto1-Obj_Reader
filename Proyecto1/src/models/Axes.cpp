#include "models/Axes.h"

void Axes::initGeometry(){
    vertices[0] = 0.0f; vertices[1] = 0.0f; vertices[2] = 0.0f; //vertice 0
    vertices[3] = 1.0f; vertices[4] = 0.0f; vertices[5] = 0.0f; //vertice 1
    vertices[6] = 0.0f; vertices[7] = 1.0f; vertices[8] = 0.0f; //vertice 2
    vertices[9] = 0.0f; vertices[10] = 0.0f; vertices[11] = 1.0f; //vertice 3

    indices[0] = 0; indices[1] = 1;
    indices[2] = 0; indices[3] = 2;
    indices[0] = 0; indices[4] = 3;
}

void Axes::init(){
    glGenVertexArrays(1,&VAO);
    glGenBuffers(1, &VBO);
    glGenBuffers(1, &EBO);

    glBindVertexArray(VAO);

    glBindBuffer(GL_ARRAY_BUFFER, VBO); 
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW); 

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(GLfloat), (GLvoid*)0);
    glEnableVertexAttribArray(0);
}

void Axes::renderModel(const glm::mat4& view, const glm::mat4& projection, GLenum mode){

    m_shaderProgram->use();

    m_shaderProgram->setMat4x4("model",m_model_mat);
    m_shaderProgram->setMat4x4("view",view);
    m_shaderProgram->setMat4x4("projection",projection);

    glBindVertexArray(VAO);
    glDrawElements(mode,6,GL_UNSIGNED_INT,0);
}

void Axes::updateModel(float deltaTime){
    deltaTime = 0;
}

void Axes::finish(){
    
}

void Axes::printInfo(){
    
}