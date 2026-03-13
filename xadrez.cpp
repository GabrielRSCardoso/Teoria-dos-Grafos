#include <iostream>
#include <string>
#include <queue>

using namespace std;

class Local{
    public:
        string codigo;
        int col(){
            int letra = codigo[0] - 'a';
            return letra;
        }
        int lin(){
            int num = codigo[1] - '1';
            return num;
        }
        

    private:
        
        char coluna;
        int linha;

};

int numMoves(Local i, Local f){
    int coli = i.col();
    int lini = i.lin();
    int colf = f.col();
    int linf = f.lin();

    int dx[8] = {2,2,-2,-2,1,1,-1,-1};
    int dy[8] = {1,-1,1,-1,2,-2,2,-2};

    bool visitado[8][8] = {false};

    queue<pair<pair<int,int>, int>> fila;

    fila.push({{coli,lini},0});
    visitado[coli][lini] = true;

    while(!fila.empty()){

        int x = fila.front().first.first;
        int y = fila.front().first.second;
        int dist = fila.front().second;

        fila.pop();

        if(x == colf && y == linf)
            return dist;

        for(int k = 0; k < 8; k++){

            int nx = x + dx[k];
            int ny = y + dy[k];

            if(nx >= 0 && nx < 8 && ny >= 0 && ny < 8 && !visitado[nx][ny]){

                visitado[nx][ny] = true;

                fila.push({{nx,ny}, dist + 1});

            }
        }
    }    
    return 0;      
}

int main(){    
    string a; 
    string b;
    while (cin >> a >> b)
    {
        Local inicio, final;
        inicio.codigo = a;
        final.codigo = b;

        cout << "To get from " << a << " to " << b << " takes " << numMoves(inicio, final) << " knight moves." << endl;
    }
    
    

    return 0;

}