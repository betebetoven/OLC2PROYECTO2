#include "nt_Bloque.h"

Bloque::Bloque(const QVector<AbstractExpr*>& instrucciones, AbstractExpr *decl, AbstractExpr *expr, AbstractExpr *aumento, bool is_while, AbstractExpr *elsebloque) : instrucciones(instrucciones), decl(decl), expr(expr), aumento(aumento), is_while(is_while), elsebloque(elsebloque) {std::cout<<"CREA BLOQUE"<<std::endl;}

Resultado* Bloque::Interpretar(Environment* env,EnvironmentFunc* ctx2) {
    Environment *envv = new Environment(env);

    Resultado* temp = new Resultado(nullptr);


    if (decl == nullptr && expr == nullptr && aumento == nullptr) {
        for (int i = 0; i < this->instrucciones.size(); i++) {
            temp = this->instrucciones[i]->Interpretar(envv,ctx2);
            // es un return? es un break, es un continue, etc....
        }
    } else if (is_while){
        if(decl != nullptr)
        Resultado *declResult = decl->Interpretar(envv,ctx2);


        while (true) {
            Resultado *exprResult = expr->Interpretar(envv,ctx2);
            //std::cout<<"VALOR DE EXPR RESULT: "<<exprResult->getValor().toString().toStdString() <<std::endl;
            if (exprResult->getValor().toBool() == false) {

                    break;
            }

            for (int i = 0; i < this->instrucciones.size(); i++) {

                temp = this->instrucciones[i]->Interpretar(envv,ctx2);
                if(temp!=nullptr)
                {
                if(temp->getValor().toString().toStdString()=="break")// aca puede ir el return como || pero primero hay que hacer las funcinoes
                {env->updateCommonVariables(envv);
                    env->report();
                    return nullptr;}
                if(temp->getValor().toString().toStdString()=="continue"&&aumento != nullptr)
                {
                    //Resultado *aumentoResult = aumento->Interpretar(envv,ctx2);
                    break;

                }}

                //env->updateCommonVariables(envv);
                // es un return? es un break, es un continue, etc....
            }


            if (aumento != nullptr)
            Resultado *aumentoResult = aumento->Interpretar(envv,ctx2);
        }
    }
    else
    {
        Resultado *exprResult = expr->Interpretar(envv,ctx2);
        //std::cout<<"VALOR DE EXPR RESULT: "<<exprResult->getValor().toString().toStdString() <<std::endl;
        if (exprResult->getValor().toBool()) {

            for (int i = 0; i < this->instrucciones.size(); i++) {
                temp = this->instrucciones[i]->Interpretar(envv,ctx2);
                if(temp!=nullptr)
                {
                if(temp->getValor().toString().toStdString()=="break")
                {env->updateCommonVariables(envv);
                    env->report();
                    return new Resultado(QString::fromStdString("break"));}
                if(temp->getValor().toString().toStdString()=="continue"&&aumento != nullptr)
                {
                    env->updateCommonVariables(envv);
                                        env->report();
                                        return new Resultado(QString::fromStdString("continue"));

                }}
            }
        }
        else if(elsebloque != nullptr)
        {
            Resultado *aux = elsebloque->Interpretar(env,ctx2);
            return aux;

        }



    }

    env->updateCommonVariables(envv);
    env->report();
    envv->report();


    return temp;
}

QString Bloque::Graficar() {
    std::stringstream  pPosicion, lPosicion,elseposicion;
    pPosicion <<(void*)this;
    QString temp = QString::fromStdString("n" + pPosicion.str()  +
                " [ label=\"BLOQUE\" fillcolor=springgreen];\n");


    for (int i = 0; i < this->instrucciones.size(); i ++){
        lPosicion.str(std::string());
        lPosicion.clear();
        lPosicion << (void*)this->instrucciones[i];

        temp +=  QString::fromStdString("n" + pPosicion.str() + " -> n"
                        + lPosicion.str()+ ";\n");
      temp += this->instrucciones[i]->Graficar();
      if(this->elsebloque != nullptr)
      {
          lPosicion.str(std::string());
          lPosicion.clear();
          lPosicion << (void*)this->elsebloque;

          temp +=  QString::fromStdString("n" + pPosicion.str() + " -> n"
                          + lPosicion.str()+ ";\n");
          temp+=this->elsebloque->Graficar();
      }
        /// es un return? es un break, es un continue, etc....
    }
    std::cout << "alv si esta vacio" << std::endl;
    return temp;
}
