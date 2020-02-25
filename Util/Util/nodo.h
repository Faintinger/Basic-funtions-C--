class nodo
{
public:
	nodo() { iPeso = 0; iOrigen = 0; iDestino = 0; }
	void setPeso(int iP) { iPeso = iP; }
	void setOrigen(int iO) { iOrigen = iO; }
	void setDestino(int iD) { iDestino = iD; }
	int getPeso() { return iPeso; }
	int getOrigen() { return iOrigen; }
	int getDestino() { return iDestino; }
private:
	int iPeso, iOrigen, iDestino;
};