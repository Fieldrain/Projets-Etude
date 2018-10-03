var Buffer = function(Name,Data,Type,DrawType,ItemSize,NumItem){
    this.name = Name;
    this.id = null;
    this.type = Type;
    this.drawType = DrawType;
    this.data = Data;
    this.itemSize = ItemSize;
    this.numItem = NumItem;

    this.create();
}

Buffer.prototype.create = function(){
    this.id = gl.createBuffer();

    gl.bindBuffer(this.type, this.id);
    gl.bufferData(this.type, this.data, this.drawType);
}

Buffer.prototype.load = function(GlType){
    gl.bindBuffer(this.type, this.id);
    gl.vertexAttribPointer(shader.getLocation(this.name), this.itemSize, GlType, false, 0, 0);

    if(this.type != gl.ELEMENT_ARRAY_BUFFER)
        gl.enableVertexAttribArray(shader.getLocation(this.name));
}

Buffer.prototype.delete = function(){
    if(this.type != gl.ELEMENT_ARRAY_BUFFER)
        gl.disableVertexAttribArray(shader.getLocation(this.name));
        
    gl.deleteBuffer(this.id);
}