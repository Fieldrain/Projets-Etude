#include "Vertices.h"

Vertices::Vertices(){

}

Vertices::Vertices(vector<Vertex*> ListVertex) :
	listVertex(ListVertex){
}

Vertices::~Vertices(){
	listVertex.clear();
}

int Vertices::length() const{
	return (int)listVertex.size();
}

int Vertices::size() const{
	return length()*sizeof(double)*P_SIZE;
}

void Vertices::append(Vertex* vertex){
	listVertex.push_back(vertex);
}

void Vertices::appendVertices(Vertices* newVertices){
	vector<Vertex*> b = newVertices->listVertex;
	listVertex.insert(listVertex.end(), b.begin(), b.end());
}

vector<Vertex*> Vertices::getList() const{
	return listVertex;
}

pair<int,double*> Vertices::getDataList(int dimension) const{
	double* dataList = new double[length() * dimension];

	int index = 0;
	for(Vertex* v : listVertex){
		Col<double> data = v->getData();

		for(int i=0;i<dimension;i++){
			dataList[index++] = data[i];
		}
	}

	return pair<int,double*>(length() * dimension * sizeof(double),dataList);
}

pair<int,double*> Vertices::getColorList(int dimension) const{
	double* colorList = new double[length() * dimension];

	int index = 0;
	for(Vertex* v : listVertex){
		Col<double> color = v->getColor();

		for(int i=0;i<dimension;i++){
			colorList[index++] = color[i];
		}
	}

	return pair<int,double*>(length() * dimension * sizeof(double),colorList);
}

vector<Col<double>> Vertices::toVector(){
	vector<Col<double>> vect;
	for(Vertex* v : listVertex){
		vect.push_back(v->getData());
	}
	return vect;
}

void Vertices::operator+=(const Vertices* v){

	for(int i=0;i<length();i++){

		Vertex * vert= (*v)[i];
		*listVertex[i] += vert;
	}

}

Vertices* Vertices::operator*(double s){
	vector<Vertex*> newList = vector<Vertex*>();

	for(int i=0;i<length();i++){
		Vertex * v1 = listVertex[i];

		newList.push_back(new Vertex(*v1*s));
	}

    return new Vertices(newList);
}

Vertices* Vertices::operator*(const Vertices* v){
    vector<Vertex*> newList = vector<Vertex*>();

	for(int i=0;i<length();i++){
		Vertex * v1 = listVertex[i];
		Vertex * v2 = (*v)[i];

		newList.push_back(new Vertex(*v1*v2));
	}

    return new Vertices(newList);
}

Vertices* Vertices::operator*(const Mat<double> m){
	vector<Vertex*> newList = vector<Vertex*>();

	for(int i=0;i<length();i++){
		Vertex * v1 = listVertex[i];

		newList.push_back(new Vertex(*v1*m));
	}

    return new Vertices(newList);
}

Vertices* Vertices::operator/(double s){
    vector<Vertex*> newList = vector<Vertex*>();

	for(int i=0;i<length();i++){
		Vertex * v1 = listVertex[i];

		newList.push_back(new Vertex(*v1/s));
	}

    return new Vertices(newList);
}

Vertices* Vertices::operator/(const Vertices* v){
    vector<Vertex*> newList = vector<Vertex*>();

	for(int i=0;i<length();i++){
		Vertex * v1 = listVertex[i];
		Vertex * v2 = (*v)[i];

		newList.push_back(new Vertex(*v1/v2));
	}

    return new Vertices(newList);
}

Vertex* Vertices::operator[](int i) const{
	if(i<=length()){
		return listVertex[i];
	}else{
		return new Vertex();
	}
}

Vertices* Vertices::operator-( const Vertices* second){
    vector<Vertex*> newList = vector<Vertex*>();

	for(int i=0;i<length();i++){
		Vertex * v1 = listVertex[i];
		Vertex * v2 = second->listVertex[i];
		
		newList.push_back(new Vertex(*v1-v2));
	}

    return new Vertices(newList);
}
Vertices* Vertices::operator+(const Vertices* second){
    vector<Vertex*> newList = vector<Vertex*>();

	for(int i=0;i<length();i++){
		Vertex * v1 = listVertex[i];
		Vertex * v2 = second->listVertex[i];
		
		newList.push_back(new Vertex(*v1+v2));
	}

    return new Vertices(newList);
}
ostream& operator<<(ostream& os, const Vertices* v){

	os << "Taille du tabeau : " << v->length() <<endl;
	for(Vertex * ve : v->listVertex){
		os << '\t' << ve <<endl;
	}
    
    return os; 
}

double Vertices::getMin(int axe) const{
	double min = numeric_limits<double>::max();

	for (Vertex* vertex : listVertex) {
		if((*vertex)[axe]<min)
			min = (*vertex)[axe];
	}

	return min;
}	

double Vertices::getMax(int axe) const{
	double max = numeric_limits<double>::min();
	
	for (Vertex* vertex : listVertex) {
		if((*vertex)[axe]>max)
			max = (*vertex)[axe];
	}

	return max;
}

Mat<double> Vertices::getMatCovariance() const{

	Mat<double> covariance = dmat(2,2,fill::zeros);

	Col<double> P0 = getMoyenne();

	for(int i=0;i<2;i++){
		for(int j=0;j<2;j++){

			for(int k=0;k<length();k++){
				Vertex* v = listVertex[k];
				covariance(i,j) += ((*v)[i]-P0(i))*((*v)[j]-P0(j));
			}
			covariance(i,j) = covariance(i,j) / length();
		}
	}

	return covariance;
}

Col<double> Vertices::getMoyenne() const{
	Col<double> P0 = dvec({0.0,0.0});

	for(int i=0;i<length();i++){
		Vertex* v = listVertex[i];
		P0(0) += (*v)[0];
		P0(1) += (*v)[1];
	}

    P0(0) = P0(0) / length();
    P0(1) = P0(1) / length();

	return P0;
}