#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <unistd.h>

#include <GL/glew.h>
#include <SDL.h>
#include <SDL_opengl.h>
#include <OpenGL/glu.h>
#include <OpenGL/glext.h>
#include <OpenGL/gl.h>


#define DESIRED_FPS 60.0
const int SCREEN_WIDTH = 800;
const int SCREEN_HEIGHT = 600;


SDL_Window *window = NULL;
SDL_GLContext gl_context;


const char *vertexShaderSource = "#version 330 core\n"
    "layout (location = 0) in vec3 aPos;\n"
    "void main()\n"
    "{\n"
    "   gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
    "}\0";
const char *fragmentShaderSource = "#version 330 core\n"
    "out vec4 FragColor;\n"
    "void main()\n"
    "{\n"
    "   FragColor = vec4(1.0f, 0.5f, 0.2f, 1.0f);\n"
    "}\n\0";


void close() {
    SDL_GL_DeleteContext(gl_context);
    SDL_DestroyWindow(window);
    window = NULL;
    SDL_Quit();
}


// bool initGL(){
//     bool success = true;
// 
//     GLenum error = GL_NO_ERROR;
//     glViewport(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT);
//     glEnable(GL_BLEND);
//     glEnable(GL_DEPTH_TEST);
// 
//     glLoadIdentity();
// 
//     error = glGetError();
//     if(error != GL_NO_ERROR){
//         std::cout << "Error initializing OpenGL 1\n" << error;
//         success = false;
//     }
// 
//     glShadeModel(GL_SMOOTH);
//     glMatrixMode(GL_MODELVIEW);
//     glLoadIdentity();
// 
// 
//     error = glGetError();
//     if(error != GL_NO_ERROR){
//         std::cout << "Error initializing OpenGL 2\n" << error;
//         success = false;
//     }
// 
//     glClearColor(1.f, 0.f, 0.f, 1.f);
// 
//     error = glGetError();
//     if(error != GL_NO_ERROR){
//         std::cout << "Error initializing OpenGL 3\n";
//         success = false;
//     }
//     return success;
// }


bool init() {
    bool success = true;
    if(SDL_Init(SDL_INIT_VIDEO) < 0){
        printf("SDL could not initialize! SDL Error: %s\n", SDL_GetError());
        success = false;
    } 
    else {
        std::cout << "SDL Opengl context created successfully\n";

        std::cout << "wtf\n";
        SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);
        SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 4);
        SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 1);
        std::cout << "made it here\n";

        //Create window
        window = SDL_CreateWindow("Holy Triangle", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_OPENGL);

        std::cout << "im here\n";
        if( window == NULL ) {
            std::cout << "Window could not be created! SDL Error:\n";
            success = false;
        }
        else {
            gl_context = SDL_GL_CreateContext(window);
            if( gl_context == NULL ) {
                std::cout << "OpenGL context could not be created! SDL Error:\n";
                success = false;
            }

            else {
                if(SDL_GL_SetSwapInterval(1) < 0) {
                    std::cout << "Warning: Unable to set VSync! SDL Error:\n";
                }
                // if(!initGL()) {
                //     std::cout << "Unable to initialize OpenGL!\n";
                //     success = false;
                // }
            }
        }
    }
    return success;
}



int main() {
    SDL_Event event;
    if(!init()){
        std::cout << "Failed to init\n";
        return 0;
    }
    std::cout << glewInit << "\n";
     // if(!glewInit()){
     //     std::cout << "glewInit failed.\n";
     //     exit(EXIT_FAILURE);
     // }
    std::cout << "here\n";

    std::cout<<glGenBuffers<<"\n";
    GLuint vbo_a = 0;
    glGenBuffers(1, &vbo_a);

    std::cout << "yo yo\n";

    GLuint vertexShader = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
    glCompileShader(vertexShader);
    
    std::cout << "Here1\n";
    // check for shader compile errors
    int success;
    char infoLog[512];
    glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);
    if (!success) {
        glGetShaderInfoLog(vertexShader, 512, NULL, infoLog);
        std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << infoLog << std::endl;
    }

    std::cout << "Here2\n";
    // fragment shader
    unsigned int fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);
    glCompileShader(fragmentShader);
    // check for shader compile errors
    glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &success);
    if(!success) {
        glGetShaderInfoLog(fragmentShader, 512, NULL, infoLog);
        std::cout << "ERROR::SHADER::FRAGMENT::COMPILATION_FAILED\n" << infoLog << std::endl;
    }

    // link shaders

    std::cout << "Here3\n";
    unsigned int shaderProgram = glCreateProgram();
    glAttachShader(shaderProgram, vertexShader);
    glAttachShader(shaderProgram, fragmentShader);
    glLinkProgram(shaderProgram);


    // check for linking errors
    glGetProgramiv(shaderProgram, GL_LINK_STATUS, &success);
    if (!success) {
        glGetProgramInfoLog(shaderProgram, 512, NULL, infoLog);
        std::cout << "ERROR::SHADER::PROGRAM::LINKING_FAILED\n" << infoLog << std::endl;
    }
    glDeleteShader(vertexShader);
    glDeleteShader(fragmentShader);

    float vertices[] = {
        -0.5f, -0.5f, 0.0f, // left  
         0.5f, -0.5f, 0.0f, // right 
         0.0f,  0.5f, 0.0f  // top   
    }; 

    std::cout << "Here4\n";
    GLuint VBO, VAO;
    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);
    glBindVertexArray(VAO);

    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);

    glBindBuffer(GL_ARRAY_BUFFER, 0); 

    glBindVertexArray(0); 

    bool quit = false;
    while(!quit) {
        while( SDL_PollEvent(&event) != 0) {
            if(event.type == SDL_QUIT) {
                quit = true;
            }
        }

        // render
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);

        glClear(GL_COLOR_BUFFER_BIT);
        glUseProgram(shaderProgram);
        glBindVertexArray(VAO);
        glDrawArrays(GL_TRIANGLES, 0, 3);
        SDL_GL_SwapWindow(window);
    }

    glDeleteVertexArrays(1, &VAO);
    glDeleteBuffers(1, &VBO);
    glDeleteProgram(shaderProgram);
    
    close();
    return 0;
}


