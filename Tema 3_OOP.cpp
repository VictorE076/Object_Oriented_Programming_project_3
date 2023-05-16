// Tema 3_OOP.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "Business.h"

int main()
{ 
    // CITIREA DE LA TASTATURA A "N" OBIECTE DE DIFERITE TIPURI (TEMA_2)!!
    /*
    std::cout << "\n\n\n-----------------CITIREA A <<N>> OBIECTE DE DIFERITE TIPURI-------------------\n\n\n";
    Contract::set_nr_total_Contracte_to_zero();
    std::cout << "Momentan sunt: " << Contract::get_nr_total_Contracte() << " contracte/abonamente(simple sau premium):\n\n\n";
    unsigned short nr_obiecte;
    std::cout << "Dati nr. de abonamente ce vor fi citite de la tastatura: ";
    std::cin >> nr_obiecte;
    std::vector<std::shared_ptr<Contract>> abonamente;
    std::cout << "\n\n--------CITIRE----------\n\n";
    for (int i = 0; i < nr_obiecte; i++)
    {
        std::shared_ptr<Contract> temp;
        std::cout << "\n\nAbonamentul nr. " << i + 1 << ":\n";
        unsigned short alegere;
        std::cout << "Apasati <<1>> pt. un abonament(simplu) sau <<2>> pt. un abonament_premium: ";
        std::cin >> alegere;
        if (alegere == 1)
        {
            temp = std::make_shared<Abonament>();
            std::cin >> *std::dynamic_pointer_cast<Abonament>(temp);
            abonamente.push_back(temp);
        }
        else if (alegere == 2)
        {
            temp = std::make_shared<Abonament_Premium>();
            std::cin >> *std::dynamic_pointer_cast<Abonament_Premium>(temp);
            abonamente.push_back(temp);
        }
        else
        {
            std::cout << "\nProgramul se va opri deoarece a fost introdusa o alegere invalida!!!\n";
            exit(-1199);
        }
    }
    std::cout << "\n\n---------AFISARE----------\n\n";
    std::cout << "S-au creat " << Contract::get_nr_total_Contracte() << " contracte/abonamente(simple sau premium):\n\n\n";
    nr_obiecte = abonamente.size();
    for (int i = 0; i < nr_obiecte; i++)
    {
        std::cout << "\n\nAbonamentul nr. " << i + 1 << ":\n";
        if (typeid(*abonamente[i]) == typeid(Abonament))
        {
            std::cout << *std::dynamic_pointer_cast<Abonament>(abonamente[i]);
        }
        else
        {
            std::cout << *std::dynamic_pointer_cast<Abonament_Premium>(abonamente[i]);
        }
    }
    */
//
//
    /*
    std::shared_ptr<Clienti> cl1 = std::make_shared<Clienti>();
    std::cin >> *cl1;
    std::cout << *cl1;
    */

    Abonat ab1(111, "Popescu Ion", "3331431", "07685", std::make_shared<Abonament_Premium>("google", 19.4, 12, 5)); // 3 desc
    Abonat ab2(222, "Ionescu Dan", "45365", "035751", std::make_shared<Abonament>("HP", 12.97, 24)); // 4 desc
    std::shared_ptr<Abonat> ab3 = std::make_shared<Abonat>(333, "Stanescu Matei", "314432", "0343", std::make_shared<Abonament_Premium>("orange", 25.01, 18, 10)); // 2 desc
    Abonat ab4(444, "Caraiman Florin", "76587", "07685", std::make_shared<Abonament>("microsoft", 29.99, 6)); // 1 desc
    std::vector<std::shared_ptr<Abonat>> v1;
    v1.push_back(std::make_shared<Abonat>(ab1));
    v1.push_back(std::make_shared<Abonat>(ab2));
    v1.push_back(ab3);
    v1.push_back(std::make_shared<Abonat>(ab4));
    std::cout << "\n\n-----------LAMBDA EXPRESSIONS------------\n\n";
    //
    float avg_price = 0.0f;
    auto sort_des = [](std::shared_ptr<Abonat> ab1, std::shared_ptr<Abonat> ab2) {
        return ab1->get_pret_Abonament() > ab2->get_pret_Abonament();
    };
    std::sort(v1.begin(), v1.end(), sort_des);
    std::for_each(v1.begin(), v1.end(), [](std::shared_ptr<Abonat> Ab) {
        std::cout << "Using LAMBDAS:\n" << *Ab << "\n";
        });
    int len = v1.size();
    std::for_each(v1.begin(), v1.end(), [&avg_price, len](std::shared_ptr<Abonat> Ab) {
        avg_price += (float)(Ab->get_pret_Abonament() / len);
        });
    std::cout << "\n\nPretul MEDIU platit de toti abonatii: " << avg_price << "\n\n";
    //
    std::shared_ptr<Clienti> cl1 = std::make_shared<Clienti>(v1);
    //
    std::cout << "\n\n----------DESIGN PATTERNS--------\n\n";
    std::cout << "\n\n------------BUILDER-----------------\n\n";
    Firma_Builder fb1;
    Firma f1;
    std::cout << f1;
    f1 = fb1.employees_count(23).location("Strada_Soarelui").create();
    std::cout << f1;
    f1 = fb1.employees_count(40).clients(cl1).create();
    std::cout << f1;
    f1 = fb1.employees_count(0).create();
    std::cout << f1;
    Firma_Builder& fb2 = fb1.location("Strada_Sperantei").employees_count(29).clients(nullptr);
    f1 = fb2.create();
    std::cout << f1;
    Firma f2 = fb2.location("Strada_Matei_Basarab").clients(cl1).employees_count(108).create();
    std::cout << f2;
    //
    std::cout << "\n\n-------FACTORY--------\n\n";
    std::shared_ptr<Firma> f3 = Firma_Factory::firma_fara_info();
    std::cout << *f3;
    f3 = std::make_shared<Firma>(fb2.employees_count(12).clients(nullptr).cod_firma("012").location("Aleea_Livezilor").create());
    std::cout << *f3;
    //////
    f3 = Firma_Factory::firma_II_Bucuresti(cl1);
    std::cout << "\n\nfirma_II_Bucuresti:\n" << *f3;
    f3 = Firma_Factory::firma_II_Cluj(cl1);
    std::cout << "\n\nfirma_II_Cluj:\n" << *f3;
    f3 = Firma_Factory::firma_SRL_Bucuresti(cl1);
    std::cout << "\n\nfirma_SRL_Bucuresti:\n" << *f3;
    f3 = Firma_Factory::firma_SRL_Cluj(cl1);
    std::cout << "\n\nfirma_SRL_Cluj:\n" << *f3;
    //
    Firma f4 = Firma_Factory::firma_II_Bucuresti_no_clients();
    std::cout << "\n\nfirma_II_Bucuresti_fara_clienti:\n" << f4;
    f4 = Firma_Factory::firma_II_Cluj_no_clients();
    std::cout << "\n\nfirma_II_Cluj_fara_clienti:\n" << f4;
    //
    std::cout << "\n\n---------------------TEMPLATES------------------\n\n";
    //
    std::vector<Abonat> v2 = { ab1, ab2, *ab3, ab4 };
    std::shared_ptr<Business<Abonat>> bu1 = std::make_shared<Business<Abonat>>(v2);
    bu1->add_part(ab4);
    bu1->add_part(*ab3);
    std::cout << *bu1;
    Business<Abonat> bu2(v2);
    Business<Abonat> bu3(*bu1);
    std::cout << bu3;
    std::cout << bu2;
    //
    std::vector<float> v3 = { 34.5, 12.56, 78.1, 43.0, -10.99, 0.01 };
    Business<float> bu4(v3);
    bu4.add_part(422.22);
    bu4.add_part(0.0f);
    std::cout << bu4;
    //
    Abonament a("amazon", 15.01, 12);
    std::vector<Abonament> v4 = { a, Abonament("digi", 9.99, 6), a, Abonament("vodafone", 12.49, 18) };
    Business<Abonament> bu5(v4);
    bu5.add_part(Abonament("sony", 5.99, 24));
    std::cout << bu5;
    Business<Abonament> bu6;
    bu6 = bu5;
    std::cout << bu6;
    //
    std::cout << "\n\n---------DELETION PART----------\n\n";
    return 0;
}



/// Citirea stringurilor se face FARA SPATII!!!

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
