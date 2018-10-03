#include "FenetrePrincipal.h"

FenetrePrincipal::FenetrePrincipal(int *argc, char **argv, Scene *s, SceneControleur *c) : scene(s), controleur(c)
{
	/* Initialize the library */
    if (!glfwInit())
		exit(EXIT_FAILURE);
    
    /* Create a windowed mode window and its OpenGL context */
	fenetre = glfwCreateWindow(800, 600, "Fractal", NULL, NULL);
	
    if (!fenetre)
    {
        glfwTerminate();
        exit(EXIT_FAILURE);
    }

    /* Make the window's context current */
    glfwMakeContextCurrent(fenetre);

    /* Initialisation d'OpenGL */
    glEnable(GL_DEPTH_TEST);
    glClearColor(0.15f, 0.15f, 0.15f, 1.f);

	glewExperimental = GL_TRUE;
	if (GLEW_OK != glewInit()) 
	{
		cout << "- glew Init failed :(" << endl;
		exit(EXIT_FAILURE);
	}
    
    std::cout << "Fabricant : " << glGetString (GL_VENDOR) << std::endl;
    std::cout << "Carte graphique: " << glGetString (GL_RENDERER) << std::endl;
    std::cout << "Version : " << glGetString (GL_VERSION) << std::endl;
    std::cout << "Version GLSL : " << glGetString (GL_SHADING_LANGUAGE_VERSION) << std::endl << std::endl;

    vector<string> uniformShader = vector<string>({"cameraPosition","materialShininess","materialSpecularColor","light.position","light.intensities","light.attenuation","light.ambientCoefficient","pas"});
	scene->InitShader(uniformShader);
    controleur->InitialisationScene();
	controleur->Abonne(this);

    // Projection matrix : 65 Field of View, 1:1 ratio, display range : 1 unit <-> 1000 units
    // ATTENTIOn l'angle est donné en radians si f GLM_FORCE_RADIANS est défini sinon en degré
    Projection = glm::perspective( 60.f, 1.0f, 1.0f, 100.f);

    cameraPosition = glm::vec3(0.,0.,3.);
    LightPosition = glm::vec3(0.,0.,0.);

}

FenetrePrincipal::~FenetrePrincipal()
{
	delete controleur;
}

void FenetrePrincipal::MiseAJour(){
	Affichage();
}

void FenetrePrincipal::Affichage(){                       
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    View       = glm::lookAt(   cameraPosition, // Camera is at (0,0,3), in World Space
                                            glm::vec3(0,0,0), // and looks at the origin
                                            glm::vec3(0,1,0)  // Head is up (set to 0,-1,0 to look upside-down)
                                             );
    Model = glm::mat4(1.0f);
    Model = glm::translate(Model,glm::vec3(0,0,cameraDistance));

    Model = glm::rotate(Model,(float)cameraAngleX,glm::vec3(1, 0, 0));
    Model = glm::rotate(Model,(float)cameraAngleY,glm::vec3(0, 1, 0));

    Model = glm::scale(Model,glm::vec3(.8, .8, .8));

    // le matériau
    //---------------
    GLfloat materialShininess=3.;
    glm::vec3 materialSpecularColor(1.,1.,1);  // couleur du materiau

    // la lumière
    //-----------
    glm::vec3 LightIntensities(1.,1.,1.);// couleur la lumiere
    GLfloat LightAttenuation =1.;
    GLfloat LightAmbientCoefficient=.1f;

    GLuint idView = scene->GetShader()->getLocation("VIEW");
    GLuint idModel = scene->GetShader()->getLocation("MODEL");
    GLuint idProj = scene->GetShader()->getLocation("PROJECTION");

    GLuint idCpos = scene->GetShader()->getLocation("cameraPosition");
    GLuint idMatShi = scene->GetShader()->getLocation("materialShininess");
    GLuint idMatSpe = scene->GetShader()->getLocation("materialSpecularColor");
    GLuint idLPos = scene->GetShader()->getLocation("light.position");
    GLuint idLInt= scene->GetShader()->getLocation("light.intensities");
    GLuint idLAtt = scene->GetShader()->getLocation("light.attenuation");
    GLuint idLAmC = scene->GetShader()->getLocation("light.ambientCoefficient");
    GLuint idPas = scene->GetShader()->getLocation("pas");

    scene->GetShader()->enable();
    glUniformMatrix4fv(idView, 1, GL_FALSE, glm::value_ptr(View));
	glUniformMatrix4fv(idModel, 1, GL_FALSE, glm::value_ptr(Model));
	glUniformMatrix4fv(idProj, 1, GL_FALSE, glm::value_ptr(Projection));

    glUniform3f(idCpos,cameraPosition.x, cameraPosition.y, cameraPosition.z);
    glUniform1f(idMatShi,materialShininess);
    glUniform3f(idMatSpe,materialSpecularColor.x,materialSpecularColor.y,materialSpecularColor.z);
    glUniform3f(idLPos,LightPosition.x,LightPosition.y,LightPosition.z);
    glUniform3f(idLInt,LightIntensities.x,LightIntensities.y,LightIntensities.z);
    glUniform1f(idLAtt,LightAttenuation);
    glUniform1f(idLAmC,LightAmbientCoefficient);
    glUniform1d(idPas,scene->GetIfs("Root")->GetPas());

	// Rendu de la scene
	//scene->AfficheRepere();
    
    scene->Affiche();

    scene->GetShader()->disable();
    
	/* Swap front and back buffers */
    glfwSwapBuffers(fenetre);
    /* Poll for and process events */
    glfwPollEvents();
}

void FenetrePrincipal::Clavier(GLFWwindow* window, int key, int scancode, int action, int mods){
    if(action == GLFW_PRESS){
        controleur->KeyPress(key);
        switch(key){
            case GLFW_KEY_KP_8: /* affichage du carre plein */
                LightPosition.y += 0.5;
            break;
            case GLFW_KEY_KP_2: /* affichage du carre plein */
                LightPosition.y -= 0.5;
            break;
            case GLFW_KEY_KP_4: /* affichage du carre plein */
                LightPosition.x -= 0.5;
            break;
            case GLFW_KEY_KP_6: /* affichage du carre plein */
                LightPosition.x += 0.5;
            break;
            case GLFW_KEY_KP_9: /* affichage du carre plein */
                LightPosition.z += 0.5;
            break;
            case GLFW_KEY_KP_3: /* affichage du carre plein */
                LightPosition.z -= 0.5;
            break;
        }
        cout << LightPosition.x <<" " <<LightPosition.y <<" " <<LightPosition.z <<endl;
	    MiseAJour();
    }
}

void FenetrePrincipal::Mouse(GLFWwindow* window, int button, int action, int mods){

	if (button == GLFW_MOUSE_BUTTON_LEFT && action == GLFW_PRESS)
    {
		presse = true;
		glfwGetCursorPos(window,&xold,&yold);
    }
    if (button == GLFW_MOUSE_BUTTON_LEFT && action == GLFW_RELEASE)
		presse = false;
    MiseAJour();
}

void FenetrePrincipal::MouseMotion(GLFWwindow* window, double xpos, double ypos){
	if (presse)
    {
        cameraAngleY = cameraAngleY + (xpos - xold);
        cameraAngleX = cameraAngleX + (ypos - yold);
    }

    xold = xpos;
    yold = ypos;
    MiseAJour();
}

void FenetrePrincipal::MouseWheel(GLFWwindow* window, double xoffset, double yoffset){
	if (yoffset < 0)
    {
        cameraDistance -= 0.2f;
    }
    else
    {
        cameraDistance += 0.2f;
    }
    MiseAJour();
}

void FenetrePrincipal::Resize(GLFWwindow* window, int iWidth, int iHeight){
    if(iHeight == 0) iHeight = 1;
		float ratio = iWidth / float(iHeight);
		glViewport(0, 0, iWidth, iHeight);
		Projection = glm::perspective(60.f,ratio, 1.0f, 100.f);
}

GLFWwindow* FenetrePrincipal::GetWindow(){
	return fenetre;
}
