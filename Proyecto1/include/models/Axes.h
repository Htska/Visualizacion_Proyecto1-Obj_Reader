#ifndef AXES_H
#define AXES_H

#include "Model.h"

class Axes: public Model
{
private:
    GLfloat vertices[12];
    GLuint indices[6];
public:

    Axes(ShaderProgram* program) : Model(program){
        initGeometry();
        init();
    }

    void initGeometry() override;

    void init() override;

    void renderModel(const glm::mat4& view, const glm::mat4& projection, GLenum mode) override;

    void updateModel(float deltaTime) override;

    void finish() override;

    void printInfo() override;
};

#endif