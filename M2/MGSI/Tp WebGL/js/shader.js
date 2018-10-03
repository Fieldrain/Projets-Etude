var ShaderType = Object.freeze({VERTEX: 0, FRAGMENT: 1, TESSELATION: 2, GEOMETRY:3});

var Shader = function(){
    this.idProgram = null;
    this.idShader = new Map();

    this.var = new Map();
}

// exemple appelle function loadShader("vertexShader",ShaderType.VERTEX)
Shader.prototype.loadShader = function(id, type){
    let hShader;

    switch(type){
        case ShaderType.FRAGMENT:
            hShader = gl.createShader(gl.FRAGMENT_SHADER);
        break;
        case ShaderType.VERTEX:
            hShader = gl.createShader(gl.VERTEX_SHADER);
        break;
        case ShaderType.TESSELATION:
            
        break;
        case ShaderType.GEOMETRY:
            
        break;
    }

    let str = document.getElementById(id).innerText;

    //associer le code du shader
    gl.shaderSource(hShader, str);
    //compiler le shader
    gl.compileShader(hShader);

    if (!gl.getShaderParameter(hShader, gl.COMPILE_STATUS)) {
        alert(gl.getShaderInfoLog(hShader));
    }else{
        this.idShader.set(type,hShader);
    }
}

Shader.prototype.create_link = function(){
    this.idProgram = gl.createProgram();

    if(this.idShader.get(ShaderType.FRAGMENT))
        gl.attachShader(this.idProgram, this.idShader.get(ShaderType.FRAGMENT));

    if(this.idShader.get(ShaderType.VERTEX))
        gl.attachShader(this.idProgram, this.idShader.get(ShaderType.VERTEX));
    
    if(this.idShader.get(ShaderType.TESSELATION))
        gl.attachShader(this.idProgram, this.idShader.get(ShaderType.TESSELATION));

    if(this.idShader.get(ShaderType.GEOMETRY))
        gl.attachShader(this.idProgram, this.idShader.get(ShaderType.GEOMETRY));

    //Lier les deux codes
    gl.linkProgram(this.idProgram);

    if (!gl.getProgramParameter(this.idProgram, gl.LINK_STATUS)) {
        alert("Could not initialise shaders");
    }
}

Shader.prototype.enable = function(){
    gl.useProgram(this.idProgram);
}

Shader.prototype.getId = function(){
    return this.idProgram;
}

Shader.prototype.addAttribute = function(name){

    let loc = gl.getAttribLocation(this.idProgram, name);
    this.var.set(name,loc);
}

Shader.prototype.addUniform = function(name){

    let loc = gl.getUniformLocation(this.idProgram, name);
    this.var.set(name,loc);
}

Shader.prototype.getLocation = function(name){
    return this.var.get(name);
}
