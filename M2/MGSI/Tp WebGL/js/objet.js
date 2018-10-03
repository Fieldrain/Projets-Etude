var ObjetType = Object.freeze({ CARRE: 0, TRIANGLE: 1, POLY1: 2, POLY2: 3, POLY3: 4, POLY4: 5, CERCLE: 6, CUBE: 7, SPHERE: 8, CUBETEX: 9 ,TORUS:10});

var Objet = function () {
    this.vertices = [];
    this.indices = [];
    this.color = [];
    this.texturesCoord = [];
    this.texture = null;
    this.buffers = new Map();
}

Objet.prototype.initTriangle = function (Color) {
    this.vertices = [
        0, 0.0, 0.0,
        1.0, 0.0, 0.0,
        1.0, 1.0, 0.0
    ];

    this.indices = [0, 1, 2];

    for (i = 0; i < (this.vertices.length / 3); i++) {
        this.color.push(Color[0]);
        this.color.push(Color[1]);
        this.color.push(Color[2]);
    }

    let vertexBuffer = new Buffer("vVertex", new Float32Array(this.vertices), gl.ARRAY_BUFFER, gl.STATIC_DRAW, 3, 3);
    let colorBuffer = new Buffer("vColor", new Float32Array(this.color), gl.ARRAY_BUFFER, gl.STATIC_DRAW, 3, 3);
    let indiceBuffer = new Buffer("indice", new Uint16Array(this.indices), gl.ELEMENT_ARRAY_BUFFER, gl.STATIC_DRAW, 3, 3);

    this.buffers.set("vVertex", vertexBuffer);
    this.buffers.set("vColor", colorBuffer);
    this.buffers.set("indice", indiceBuffer);
}

Objet.prototype.initCarre = function (Color) {
    this.vertices = [
        0.0, 0.0, 0.0,
        1.0, 0.0, 0.0,
        1.0, 1.0, 0.0,
        0.0, 1.0, 0.0
    ];

    this.indices = [0, 1, 2, 2, 3, 0];

    for (i = 0; i < (this.vertices.length / 3); i++) {
        this.color.push(Color[0]);
        this.color.push(Color[1]);
        this.color.push(Color[2]);
    }

    let vertexBuffer = new Buffer("vVertex", new Float32Array(this.vertices), gl.ARRAY_BUFFER, gl.STATIC_DRAW, 3, 4);
    let colorBuffer = new Buffer("vColor", new Float32Array(this.color), gl.ARRAY_BUFFER, gl.STATIC_DRAW, 3, 4);
    let indiceBuffer = new Buffer("indice", new Uint16Array(this.indices), gl.ELEMENT_ARRAY_BUFFER, gl.STATIC_DRAW, 1, 6);

    this.buffers.set("vVertex", vertexBuffer);
    this.buffers.set("vColor", colorBuffer);
    this.buffers.set("indice", indiceBuffer);
}

Objet.prototype.initCubeTex = function () {
    this.vertices = [
        // Front face
        -1.0, -1.0, 1.0,
        1.0, -1.0, 1.0,
        1.0, 1.0, 1.0,
        -1.0, 1.0, 1.0,

        // Back face
        -1.0, -1.0, -1.0,
        -1.0, 1.0, -1.0,
        1.0, 1.0, -1.0,
        1.0, -1.0, -1.0,

        // Top face
        -1.0, 1.0, -1.0,
        -1.0, 1.0, 1.0,
        1.0, 1.0, 1.0,
        1.0, 1.0, -1.0,

        // Bottom face
        -1.0, -1.0, -1.0,
        1.0, -1.0, -1.0,
        1.0, -1.0, 1.0,
        -1.0, -1.0, 1.0,

        // Right face
        1.0, -1.0, -1.0,
        1.0, 1.0, -1.0,
        1.0, 1.0, 1.0,
        1.0, -1.0, 1.0,

        // Left face
        -1.0, -1.0, -1.0,
        -1.0, -1.0, 1.0,
        -1.0, 1.0, 1.0,
        -1.0, 1.0, -1.0,
    ];

    this.indices = [
        0, 1, 2, 0, 2, 3,    // front
        4, 5, 6, 4, 6, 7,    // back
        8, 9, 10, 8, 10, 11,   // top
        12, 13, 14, 12, 14, 15,   // bottom
        16, 17, 18, 16, 18, 19,   // right
        20, 21, 22, 20, 22, 23,   // left
    ];

    this.texturesCoord = [
        // Front
        0.0, 0.0,
        1.0, 0.0,
        1.0, 1.0,
        0.0, 1.0,
        // Back
        0.0, 0.0,
        1.0, 0.0,
        1.0, 1.0,
        0.0, 1.0,
        // Top
        0.0, 0.0,
        1.0, 0.0,
        1.0, 1.0,
        0.0, 1.0,
        // Bottom
        0.0, 0.0,
        1.0, 0.0,
        1.0, 1.0,
        0.0, 1.0,
        // Right
        0.0, 0.0,
        1.0, 0.0,
        1.0, 1.0,
        0.0, 1.0,
        // Left
        0.0, 0.0,
        1.0, 0.0,
        1.0, 1.0,
        0.0, 1.0,
    ];

    let vertexBuffer = new Buffer("vVertex", new Float32Array(this.vertices), gl.ARRAY_BUFFER, gl.STATIC_DRAW, 3, (this.vertices.length / 3));
    let textureBuffer = new Buffer("vTextureCoord", new Float32Array(this.texturesCoord), gl.ARRAY_BUFFER, gl.STATIC_DRAW, 2, (this.texturesCoord.length / 2));
    let indiceBuffer = new Buffer("indice", new Uint16Array(this.indices), gl.ELEMENT_ARRAY_BUFFER, gl.STATIC_DRAW, 1, this.indices.length);

    this.buffers.set("vVertex", vertexBuffer);
    this.buffers.set("vTextureCoord", textureBuffer);
    this.buffers.set("indice", indiceBuffer);
}

Objet.prototype.initCube = function (Color) {
    this.vertices = [
        // Front face
        -1.0, -1.0, 1.0,
        1.0, -1.0, 1.0,
        1.0, 1.0, 1.0,
        -1.0, 1.0, 1.0,

        // Back face
        -1.0, -1.0, -1.0,
        -1.0, 1.0, -1.0,
        1.0, 1.0, -1.0,
        1.0, -1.0, -1.0,

        // Top face
        -1.0, 1.0, -1.0,
        -1.0, 1.0, 1.0,
        1.0, 1.0, 1.0,
        1.0, 1.0, -1.0,

        // Bottom face
        -1.0, -1.0, -1.0,
        1.0, -1.0, -1.0,
        1.0, -1.0, 1.0,
        -1.0, -1.0, 1.0,

        // Right face
        1.0, -1.0, -1.0,
        1.0, 1.0, -1.0,
        1.0, 1.0, 1.0,
        1.0, -1.0, 1.0,

        // Left face
        -1.0, -1.0, -1.0,
        -1.0, -1.0, 1.0,
        -1.0, 1.0, 1.0,
        -1.0, 1.0, -1.0,
    ];

    this.indices = [
        0, 1, 2, 0, 2, 3,    // front
        4, 5, 6, 4, 6, 7,    // back
        8, 9, 10, 8, 10, 11,   // top
        12, 13, 14, 12, 14, 15,   // bottom
        16, 17, 18, 16, 18, 19,   // right
        20, 21, 22, 20, 22, 23,   // left
    ];

    for (i = 0; i < (this.vertices.length / 3); i++) {
        this.color.push(Color[0]);
        this.color.push(Color[1]);
        this.color.push(Color[2]);
    }

    let vertexBuffer = new Buffer("vVertex", new Float32Array(this.vertices), gl.ARRAY_BUFFER, gl.STATIC_DRAW, 3, (this.vertices.length / 3));
    let colorBuffer = new Buffer("vColor", new Float32Array(this.color), gl.ARRAY_BUFFER, gl.STATIC_DRAW, 3, (this.color.length / 3));
    let indiceBuffer = new Buffer("indice", new Uint16Array(this.indices), gl.ELEMENT_ARRAY_BUFFER, gl.STATIC_DRAW, 1, this.indices.length);

    this.buffers.set("vVertex", vertexBuffer);
    this.buffers.set("vColor", colorBuffer);
    this.buffers.set("indice", indiceBuffer);
}

Objet.prototype.initCercle = function (Color, diametre, cote, origin) {
    let rayon = diametre / 2;

    this.vertices.push(origin[0]);
    this.vertices.push(origin[1]);

    this.color.push(Color[0]);
    this.color.push(Color[1]);
    this.color.push(Color[2]);

    for (i = 0; i <= cote; i++) {
        this.vertices.push(origin[0] + (rayon * Math.cos(i * 2 * Math.PI / cote)));
        this.vertices.push(origin[0] + (rayon * Math.sin(i * 2 * Math.PI / cote)));

        this.color.push(Color[0]);
        this.color.push(Color[1]);
        this.color.push(Color[2]);

        this.indices.push(i);
        this.indices.push(0);
        this.indices.push(i + 1);
    }

    let vertexBuffer = new Buffer("vVertex", new Float32Array(this.vertices), gl.ARRAY_BUFFER, gl.DYNAMIC_DRAW, 2, (this.vertices.length / 2));
    let colorBuffer = new Buffer("vColor", new Float32Array(this.color), gl.ARRAY_BUFFER, gl.DYNAMIC_DRAW, 3, (this.color.length / 3));
    let indiceBuffer = new Buffer("indice", new Uint16Array(this.indices), gl.ELEMENT_ARRAY_BUFFER, gl.DYNAMIC_DRAW, 3, this.indices.length);

    this.buffers.set("vVertex", vertexBuffer);
    this.buffers.set("vColor", colorBuffer);
    this.buffers.set("indice", indiceBuffer);
}

Objet.prototype.initSphere = function (Color, diametre, meridien, parallele, origin) {

    //init sommet
    let rayon = diametre / 2;
    let o = 0;

    for (let i = 0; i < meridien; i++) {
        let y = (-(Math.PI / 2) + (Math.PI / (parallele + 1)));

        for (let j = 0; j < parallele; j++) {
            this.vertices.push(origin[0] + (rayon * (Math.cos(y) * Math.sin(o))));
            this.vertices.push(origin[1] + (rayon * Math.sin(y)));
            this.vertices.push(origin[2] + (rayon * (Math.cos(o) * Math.cos(y))));

            this.color.push(Color[0]);
            this.color.push(Color[1]);
            this.color.push(Color[2]);

            y += (Math.PI / (parallele + 1));
        }
        o += ((2 * Math.PI) / meridien);
    }

    this.vertices.push(origin[0] + 0.0);
    this.vertices.push(origin[1] + rayon);
    this.vertices.push(origin[2] + 0.0);

    this.color.push(0);
    this.color.push(0);
    this.color.push(0);

    this.vertices.push(origin[0] + 0.0);
    this.vertices.push(origin[1] + -rayon);
    this.vertices.push(origin[2] + 0.0);

    this.color.push(0);
    this.color.push(0);
    this.color.push(0);

    //init indice
    for (let i = 0; i < parallele - 1; i++) {
        for (let j = 0; j < meridien; j++) {
            this.indices.push(i + (j * parallele));
            this.indices.push((i + 1) + (j * parallele));
            this.indices.push(((i + 1) + ((j + 1) * parallele)) % (parallele * meridien));

            this.indices.push(((i + 1) + ((j + 1) * parallele)) % (parallele * meridien));
            this.indices.push(i + (j * parallele));
            this.indices.push((i + (j + 1) * parallele) % (parallele * meridien));
        }
    }

    for (let j = 0; j < meridien; j++) {
        this.indices.push((this.vertices.length / 3) - 1);
        this.indices.push(j * parallele);
        this.indices.push(((j + 1) * parallele) % (parallele * meridien));
    }

    for (let j = 0; j < meridien; j++) {
        this.indices.push((this.vertices.length / 3) - 2);
        this.indices.push((parallele - 1) + (j * parallele));
        this.indices.push(((parallele - 1) + ((j + 1) * parallele)) % (parallele * meridien));
    }

    let vertexBuffer = new Buffer("vVertex", new Float32Array(this.vertices), gl.ARRAY_BUFFER, gl.STATIC_DRAW, 3, (this.vertices.length / 3));
    let colorBuffer = new Buffer("vColor", new Float32Array(this.color), gl.ARRAY_BUFFER, gl.STATIC_DRAW, 3, (this.color.length / 3));
    let indiceBuffer = new Buffer("indice", new Uint16Array(this.indices), gl.ELEMENT_ARRAY_BUFFER, gl.STATIC_DRAW, 1, this.indices.length);

    this.buffers.set("vVertex", vertexBuffer);
    this.buffers.set("vColor", colorBuffer);
    this.buffers.set("indice", indiceBuffer);
}

Objet.prototype.initTorus = function (Color, R, r,NB_R,NB_r) {

    this.vertices.fill(0,0,(NB_R+1)*(NB_r+1)*3);
    this.indices.fill(0,0,NB_R*NB_r*6);

    let theta, phi;
    theta = (360*(Math.PI/180)) / (NB_R);
    phi = (360*(Math.PI/180)) / (NB_r);

    let pasU, pasV;
    pasU = 1. / NB_R;
    pasV = 1. / NB_r;
    for (let i = 0; i <= NB_R; i++){
        for (let j = 0; j <= NB_r; j++) {
            let a, b, c;
            this.vertices[(i * (NB_r + 1) * 3) + (j * 3)] = (R + r * Math.cos(j * phi)) * Math.cos(i * theta);//x
            this.vertices[(i * (NB_r + 1) * 3) + (j * 3) + 1] = (R + r * Math.cos(j * phi)) * Math.sin(i * theta);//y
            this.vertices[(i * (NB_r + 1) * 3) + (j * 3) + 2] = r * Math.sin(j * phi);
        }
    }

    let indiceMaxI = ((NB_R + 1) * (NB_r)) - 1;
    let indiceMaxJ = (NB_r + 1);

    for (let i = 0; i < NB_R; i++){
        for (let j = 0; j < NB_r; j++) {
            let i0, i1, i2, i3, i4, i5;
            this.indices[(i * NB_r * 6) + (j * 6)] = ((i * (NB_r + 1)) + j);
            this.indices[(i * NB_r * 6) + (j * 6) + 1] = ((i + 1) * (NB_r + 1) + (j));
            this.indices[(i * NB_r * 6) + (j * 6) + 2] = (((i + 1) * (NB_r + 1)) + (j + 1));
            this.indices[(i * NB_r * 6) + (j * 6) + 3] = ((i * (NB_r + 1)) + j);
            this.indices[(i * NB_r * 6) + (j * 6) + 4] = (((i + 1) * (NB_r + 1)) + (j + 1));
            this.indices[(i * NB_r * 6) + (j * 6) + 5] = (((i) * (NB_r + 1)) + (j + 1));
        }
    }

    for (let i = 0; i < (this.vertices.length / 3); i++) {
        this.color.push(Color[0]);
        this.color.push(Color[1]);
        this.color.push(Color[2]);
    }

    let vertexBuffer = new Buffer("vVertex", new Float32Array(this.vertices), gl.ARRAY_BUFFER, gl.STATIC_DRAW, 3, (this.vertices.length / 3));
    let colorBuffer = new Buffer("vColor", new Float32Array(this.color), gl.ARRAY_BUFFER, gl.STATIC_DRAW, 3, (this.color.length / 3));
    let indiceBuffer = new Buffer("indice", new Uint16Array(this.indices), gl.ELEMENT_ARRAY_BUFFER, gl.STATIC_DRAW, 1, this.indices.length);

    this.buffers.set("vVertex", vertexBuffer);
    this.buffers.set("vColor", colorBuffer);
    this.buffers.set("indice", indiceBuffer);

    console.log(this);
}

Objet.prototype.loadTexture = function (url) {
    function isPowerOf2(value) {
        return (value & (value - 1)) == 0;
    }

    let texture = gl.createTexture();
    gl.bindTexture(gl.TEXTURE_2D, texture);

    gl.texImage2D(gl.TEXTURE_2D, 0, gl.RGBA, 1, 1, 0, gl.RGBA, gl.UNSIGNED_BYTE, new Uint8Array([0, 0, 255, 255]));

    let image = new Image();
    image.onload = function () {
        gl.bindTexture(gl.TEXTURE_2D, texture);
        gl.texImage2D(gl.TEXTURE_2D, 0, gl.RGBA, gl.RGBA, gl.UNSIGNED_BYTE, image);

        if (isPowerOf2(image.width) && isPowerOf2(image.height)) {
            gl.generateMipmap(gl.TEXTURE_2D);
        } else {
            gl.texParameteri(gl.TEXTURE_2D, gl.TEXTURE_WRAP_S, gl.CLAMP_TO_EDGE);
            gl.texParameteri(gl.TEXTURE_2D, gl.TEXTURE_WRAP_T, gl.CLAMP_TO_EDGE);
            gl.texParameteri(gl.TEXTURE_2D, gl.TEXTURE_MIN_FILTER, gl.LINEAR);
        }
    };
    image.src = url;

    this.texture = texture;
}

Objet.prototype.delete = function () {
    delete this.vertices;
    delete this.indices;
    delete this.color;
    delete this.texturesCoord;
    delete this.texture;

    let vVertex = objet.buffers.get("vVertex");
    let vColor = objet.buffers.get("vColor");
    let indice = objet.buffers.get("indice");
    let textureBuffer = objet.buffers.get("vTextureCoord");

    if (vVertex)
        vVertex.delete();

    if (vColor)
        vColor.delete();

    if (textureBuffer)
        textureBuffer.delete();

    if (indice)
        indice.delete();

    this.vertices = [];
    this.indices = [];
    this.color = [];
    this.texturesCoord = [];
    this.texture = null;
    this.buffers = new Map();
}