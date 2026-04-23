#include<bits/stdc++.h>
using namespace std;
constexpr int INF=1<<30-1;
struct Node{
    int name;
    int row;
    int sz;
    Node* col;

    Node* up;
    Node* down;
    Node* left;
    Node* right;

    Node(){
        this->row=-1;
        this->sz=0;
        this->col=this->up=this->down=this->left=this->right=this;
    }
    Node(int row,int sz,Node* col){
        this->row=row;
        this->sz=sz;
        this->col=col;
        this->up=this->down=this->left=this->right=this;
    }
    void add_right(Node* r){
        //cout<<"1";
        this->right->left=r;
        //cout<<"2";
        r->right=this->right;
        //cout<<"3";
        r->left=this;
        //cout<<"4";
        this->right=r;
        //cout<<"5";
        return;
    }
    void add_left(Node* r){
        this->left->right=r;
        r->left=this->left;
        r->right=this;
        this->left=r;
        return;
    }
    void add_down(Node* r){
        this->down->up=r;
        r->down=this->down;
        r->up=this;
        this->down=r;
        return;
    }
    void add_up(Node* r){
        this->up->down=r;
        r->up=this->up;
        r->down=this;
        this->up=r;
        return;
    }
};

void cover(Node* c){
    c->right->left=c->left;
    c->left->right=c->right;

    for(Node* it=c->down;it!=c;it=it->down){
        for(Node *jt=it->right;jt!=it;jt=jt->right){
            jt->down->up=jt->up;
            jt->up->down=jt->down;
            jt->col->sz--;
        }
    }
    return;
}
void uncover(Node *c){
    for(Node *it=c->up;it!=c;it=it->up){
        for(Node* jt=it->left;jt!=it;jt=jt->left){
            jt->down->up=jt;
            jt->up->down=jt;
            jt->col->sz++;
        }
    }
    c->right->left=c;
    c->left->right=c;
    return;
}
bool dlx_search(Node* head,int k,vector<int>& solution){
    if(head->right==head)return 1;
    //cout<<"1";
    Node* ans=new Node;
    int mn=INF;

    for(Node* it=head->right;it!=head;it=it->right){
        if(it->sz<mn){
            if(it->sz==0)return 0;
            mn=it->sz;
            ans=it;
        }
    }
//cout<<"2";
    cover(ans);
//cout<<"3";
    for(Node* it=ans->down;it!=ans;it=it->down){
        solution.push_back(it->row);
        for(Node* jt=it->right;jt!=it;jt=jt->right){
            cover(jt->col);
        }
        if(dlx_search(head,k+1,solution))return 1;
        else{
            solution.pop_back();
            for(Node* jt=it->left;jt!=it;jt=jt->left){
                uncover(jt->col);
            }
        }
    }
    //cout<<"4";
    uncover(ans);
    return 0;
}
void solve(string s){
    int sudoku[9][9];
    int i,j;
    for(i=0;i<9;i++){
        for(j=0;j<9;j++){
            char nowchar=s[9*i+j];
            if(nowchar=='.')sudoku[i][j]=0;
            else sudoku[i][j]=nowchar-'0';
        }
    }
    vector<vector<int>> mat;
    vector<tuple<int,int,int>> row_data;
    vector<Node*> column(324);
    //for(i=0;i<324;i++)cout<<column[i]->sz;
    Node* head=new Node();
    head->name=0;
    for(i=0;i<324;i++){
        column[i]=new Node();
        column[i]->name=i+1;

        if(i==0){
            head->add_right(column[0]);
        }
        else column[i-1]->add_right(column[i]);
    }
    //cout<<column[323]->right->name<<"ds\n";

    for(i=0;i<9;i++){
        for(j=0;j<9;j++){
            //cin>>sudoku[i][j];
            auto make_row=[&](int x){
                vector<int> row(324);
                row[9*(i)+j]=1;
                row[80+9*(i)+x]=1;
                row[161+9*(j)+x]=1;
                row[242+((i)/3*3+(j)/3)*9+x]=1;
                mat.push_back(row);
                row_data.push_back({i,j,x});
            };
            if(sudoku[i][j])make_row(sudoku[i][j]);
            else for(int k=1;k<=9;k++)make_row(k);
        }
    }
    for(i=0;i<mat.size();i++){
        Node* last=nullptr;
        for(j=0;j<324;j++){
            if(mat[i][j]==1){
                Node* now=new Node(i,0,column[j]);
                column[j]->add_up(now);
                if(last){
                    last->add_right(now);
                }
                column[j]->sz++;
                last=now;
            }
        }
    }
    /*for(Node* it=head->right;it!=head;it=it->right){

        cout<<it->sz<<" ";if(it->name%9==0)cout<<"\n";
    }*/
    vector<int> solution;
    dlx_search(head,0,solution);//cout<<"x";
    //cout<<solution.size()<<"s\n";
    for(auto &k:solution){
        auto [i,j,x]=row_data[k];
        //cout<<i<<" "<<j<<" "<<x<<"\n";
        sudoku[i][j]=x;
    }
    for(i=0;i<9;i++){
        for(j=0;j<9;j++){
            cout<<sudoku[i][j];
        }
        //cout<<"\n";
    }
    cout<<"\n";
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    while(1){
        string s;
        cin>>s;
        if(s=="end")break;
        solve(s);
    }
}