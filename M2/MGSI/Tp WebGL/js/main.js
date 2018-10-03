var gl;
//declaration de la matrice de mod�lisation (model-view)
var mvMatrix;
//declaration de la matrice de projection
var pMatrix;
// declaration objet shader
var shader = new Shader();
var objet = new Objet();
var angle=0;

var typeCourant = ObjetType.CUBE;

function start(){

    let canvas = document.getElementById("canvas");
    initWebGL(canvas);
    initShaders();
    initObject();
    affichage();
}

function initWebGL (canvas) {
    try {
        gl = canvas.getContext("webgl");

    } catch (e) {
		alert("Impossible d'initialiser le WebGL !");
    }
}

function initGL() {
	//preparation de la scene
    gl.clearColor(0.0, 0.7, 0.7, 1.0);  // Clear to black, fully opaque
    gl.clearDepth(1.0);                 // Clear everything

    gl.enable(gl.DEPTH_TEST);           // Enable depth testing
    gl.depthFunc(gl.LEQUAL);            // Near things obscure far things

    gl.enable(gl.BLEND);
    gl.blendFunc(gl.SRC_ALPHA, gl.ONE_MINUS_SRC_ALPHA);
    
    // Clear the canvas before we start drawing on it.
    gl.clear(gl.COLOR_BUFFER_BIT | gl.DEPTH_BUFFER_BIT);
}

function initObject(){
    function hexToRgb(hex) {
        // Expand shorthand form (e.g. "03F") to full form (e.g. "0033FF")
        var shorthandRegex = /^#?([a-f\d])([a-f\d])([a-f\d])$/i;
        hex = hex.replace(shorthandRegex, function(m, r, g, b) {
            return r + r + g + g + b + b;
        });
    
        var result = /^#?([a-f\d]{2})([a-f\d]{2})([a-f\d]{2})$/i.exec(hex);
        return result ? {
            r: parseInt(result[1], 16),
            g: parseInt(result[2], 16),
            b: parseInt(result[3], 16)
        } : null;
    }

    let c = hexToRgb(document.getElementById('html5colorpicker').value);
    let color = [c.r/255,c.g/255,c.b/255];

    switch(typeCourant){
        case ObjetType.CARRE:
            objet.initCarre(color);
        break;
        case ObjetType.TRIANGLE:
            objet.initTriangle(color);
        break;
        case ObjetType.CERCLE:
            objet.initCercle(color,2,10,[0,0,0]);
        break;
        case ObjetType.CUBE:
            objet.initCube(color);
        break;
        case ObjetType.SPHERE:
            objet.initSphere(color,2,50,50,[0,0,0]);
        break;
        case ObjetType.POLY1:
            objet.initCercle(color,2,5,[0,0,0]);
        break;
        case ObjetType.POLY2:
            objet.initCercle(color,2,6,[0,0,0]);
        break;
        case ObjetType.POLY3:
            objet.initCercle(color,2,7,[0,0,0]);
        break;
        case ObjetType.POLY4:
            objet.initCercle(color,2,8,[0,0,0]);
        break;
        case ObjetType.TORUS:
            objet.initTorus(color,1,0.5,40,20);
        break;
        case ObjetType.CUBETEX:
            objet.initCubeTex();
        break;
        
    }

    objet.loadTexture('img/flocon.png');
}

function initShaders(){
    shader.loadShader("shader-fs",ShaderType.FRAGMENT);
    shader.loadShader("shader-vs",ShaderType.VERTEX);

    shader.create_link();

    shader.addAttribute("vVertex");
    shader.addAttribute("vColor");
    shader.addAttribute("vTextureCoord");

    shader.addUniform("Projection");
    shader.addUniform("ModelView");
    shader.addUniform("uTexture");
    shader.addUniform("useTexture");
}

function drawScene(){
    pMatrix= mat4.create();
    mat4.perspective(pMatrix, 45 * Math.PI / 180, gl.canvas.clientWidth / gl.canvas.clientHeight, 0.1, 10.0);

    mvMatrix = mat4.create();

    mat4.translate(mvMatrix,mvMatrix, [0., 0., -6.0]);
    mat4.rotate(mvMatrix,mvMatrix, angle, [0, 1, 0]);
    mat4.rotate(mvMatrix,mvMatrix, angle, [1, 0, 0]);

    shader.enable();
    
    gl.uniformMatrix4fv(shader.getLocation("Projection"), false, pMatrix);
    gl.uniformMatrix4fv(shader.getLocation("ModelView"), false, mvMatrix);
    gl.uniform1i(shader.getLocation("useTexture"),false);

    let vVertex = objet.buffers.get("vVertex");
    let vColor = objet.buffers.get("vColor");
    let indice = objet.buffers.get("indice");
    let textureBuffer = objet.buffers.get("vTextureCoord");

    vVertex.load(gl.FLOAT);

    if (vColor)
        vColor.load(gl.FLOAT);

    if (textureBuffer && typeCourant == ObjetType.CUBETEX) {
        textureBuffer.load(gl.FLOAT);
        // Indiquer à WebGL que nous voulons affecter l'unité de texture 0
        gl.activeTexture(gl.TEXTURE0);
        // Lier la texture à l'unité de texture 0
        gl.bindTexture(gl.TEXTURE_2D, objet.texture);
        // Indiquer au shader que nous avons lié la texture à l'unité de texture 0
        gl.uniform1i(shader.getLocation("uTexture"), 0);
        gl.uniform1i(shader.getLocation("useTexture"),true);
    }

    if(indice) {
        gl.drawElements(gl.TRIANGLES, indice.numItem, gl.UNSIGNED_SHORT, 0);
    } else {
        gl.drawArrays(gl.TRIANGLES, 0, vVertex.numItem);
    }
}

function affichage(){
    window.requestAnimationFrame(affichage);
    animation();
    initGL();
    drawScene();
}

function animation(){
    angle += 0.01;
}

function refresh(){
    objet.delete();
    initObject();
}

function carre(){
    typeCourant = ObjetType.CARRE;
    refresh();
}

function triangle(){
    typeCourant = ObjetType.TRIANGLE;
    refresh();
}

function cercle(){
    typeCourant = ObjetType.CERCLE;
    refresh();
}

function cube(){
    typeCourant = ObjetType.CUBE;
    refresh();
}

function cubeTex(){
    typeCourant = ObjetType.CUBETEX;
    refresh();
}

function sphere(){
    typeCourant = ObjetType.SPHERE;
    refresh();
}

function poly1(){
    typeCourant = ObjetType.POLY1;
    refresh();
}

function poly2(){
    typeCourant = ObjetType.POLY2;
    refresh();
}

function poly3(){
    typeCourant = ObjetType.POLY3;
    refresh();
}

function poly4(){
    typeCourant = ObjetType.POLY4;
    refresh();
}

function torus(){
    typeCourant = ObjetType.TORUS;
    refresh();
}