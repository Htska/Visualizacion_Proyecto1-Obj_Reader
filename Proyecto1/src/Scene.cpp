#include "Scene.h"

void Scene::init(){
    //Inicializacion de ventana 
    m_window = new WindowGL();
    //Inicializacion de ProgramShader 
    m_shaderProgram = new ShaderProgram("shaders/vertex_shader.glsl","shaders/frag_shader.glsl");
    //Inicializacion del Modelo -> Cubo 
    //m_model = new Cube(m_shaderProgram);
    Model* axes = new Axes(m_shaderProgram);
    Model* model1 = new ImportedModel(m_shaderProgram,"assets/obj/bunny.obj");
    Model* model2 = new ImportedModel(m_shaderProgram,"assets/obj/Cube_Triangles.obj");
    Model* model3 = new ImportedModel(m_shaderProgram,"assets/obj/dragon.obj");
    Model* model4 = new ImportedModel(m_shaderProgram,"assets/obj/Happy_Buddha.obj");
    Model* model5 = new ImportedModel(m_shaderProgram,"assets/obj/Teapot.obj");
    m_models.push_back(model1);
    m_models.push_back(model2);
    m_models.push_back(model3);
    m_models.push_back(model4);
    m_models.push_back(model5);
    m_models.push_back(axes);
    //Matriz de vista View Matrix
    m_view =  glm::lookAt(glm::vec3(2.0f,1.0f,2.0f), glm::vec3(0.0f), glm::vec3(0.0,1.0,0.0));
    //Matriz de projeccion
    m_projection = glm::perspective(glm::radians(45.0f), m_window->getAspectRation(), 0.1f, 100.0f);
}

void Scene::render() const {

    Model* m_model = m_models[0];
    m_model->printInfo();
    float axis = 0.0f;
    GLenum mode = GL_TRIANGLES;
    //Ciclo de Renderizado
    glEnable(GL_DEPTH_TEST);  // Prueba de profundidad
    glEnable(GL_CULL_FACE);   // Habilitar culling de caras
    glCullFace(GL_BACK);      // Culling de caras traseras
    glFrontFace(GL_CCW);      // Las caras frontales son las que tienen vértices en sentido antihorario

    while(!glfwWindowShouldClose(m_window->getWindow())){

        // Compute time  
        if (glfwGetKey(m_window->getWindow(), GLFW_KEY_ESCAPE) == GLFW_PRESS)
            glfwSetWindowShouldClose(m_window->getWindow(), true);
        if (glfwGetKey(m_window->getWindow(), GLFW_KEY_0) == GLFW_PRESS){
            m_model = m_models[0];
            m_model->printInfo();
        }
        if (glfwGetKey(m_window->getWindow(), GLFW_KEY_1) == GLFW_PRESS){
            m_model = m_models[1];
            m_model->printInfo();
        }
        if (glfwGetKey(m_window->getWindow(), GLFW_KEY_2) == GLFW_PRESS){
            m_model = m_models[2];
            m_model->printInfo();
        }
        if (glfwGetKey(m_window->getWindow(), GLFW_KEY_3) == GLFW_PRESS){
            m_model = m_models[3];
            m_model->printInfo();
        }
        if (glfwGetKey(m_window->getWindow(), GLFW_KEY_4) == GLFW_PRESS){
            m_model = m_models[4];
            m_model->printInfo();
        }

        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        if (glfwGetKey(m_window->getWindow(), GLFW_KEY_T) == GLFW_PRESS){
            mode = GL_TRIANGLES;
        }

        if (glfwGetKey(m_window->getWindow(), GLFW_KEY_P) == GLFW_PRESS){
            mode = GL_POINTS;
        }

        if (glfwGetKey(m_window->getWindow(), GLFW_KEY_L) == GLFW_PRESS){
            mode = GL_LINES;
        }

        m_model->renderModel(m_view, m_projection,mode);
        m_models[5]->renderModel(m_view, m_projection,GL_LINES);
        // update models 
        glfwSwapBuffers(m_window->getWindow());
        glfwPollEvents();


        if (glfwGetKey(m_window->getWindow(), GLFW_KEY_X) == GLFW_PRESS){
            axis = 1.0f;
        }
        if (glfwGetKey(m_window->getWindow(), GLFW_KEY_Y) == GLFW_PRESS){
            axis = 2.0f;
        }
        if (glfwGetKey(m_window->getWindow(), GLFW_KEY_Z) == GLFW_PRESS){
            axis = 3.0f;
        }
        if (glfwGetKey(m_window->getWindow(), GLFW_KEY_N) == GLFW_PRESS){
            axis = 0.0f;
        }
        m_model->updateModel(axis);  
    }

}