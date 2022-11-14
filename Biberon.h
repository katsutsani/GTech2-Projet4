#pragma once


class Biberon {
	protected:
		int heure_de_prise,
			volume_bib,
			intervalle_de_rappel,
			quantit�_min,
			quantit�_max;
		bool oui_bib_pris,
			vomi;
	public:
		Biberon();
		~Biberon();
		Biberon(int hour, int volume, int rappel,int Qmin,int Qmax);
		void add_rappel(int);
		void add_hour(int,int);
		void regurgitation(bool);
};

