#include "dialogoak.h"
#include "dialogo.h"


void DIALOGO_inizializatuAxolote(struct Dialogo** dialogo)
{
	*dialogo = DIALOGO_sortu(
		"",
		"Kaixo! Axolote bat naiz eta laku azpi-azpian bizi naiz, baina ez denbora luzerako.",
		(struct Dialogo* []) {
		DIALOGO_sortu(
			"Aiba! Zergatik?",
			"Izan ere, desagertzen ari gara hainbat arrazoirengatik: habitat-galera, arrantza, espezie inbaditzaileak gure habitatean sartzea, gehiegizko ustiapena eta kutsadura.",
			(struct Dialogo* []) {
			DIALOGO_sortu(
				"Ze ondorio izango zituen horrek?",
				"Gu desagertzen bagara, beste espezie batzuk arriskuan jar daitezke. Hain zuzen ere, badaude gu jaten gaituzten bizidunak eta gu desagertzen bagara, gure harrapatzaileak jatekorik gabe geldi daitezke.",
				(struct Dialogo* []) {
				DIALOGO_sortu(
					"Zer egin dezakegu hori gelditzeko?",
					"Gure espeziea oraindik salba daiteke antzinako nekazaritza-jardunen berpizkundea sustatuz gero eta ondoren, nekazarien kanalen segmentuak guretzako santutegi bihurtuz gero.",
					(struct Dialogo* []) {
					DIALOGO_sortu(
						"Mila esker zure dialoagatik! Agur!",
						"",
						(struct Dialogo* []) {
						0,
					},
						0
					)
				},
					1
				)
			},
				1
			)
		},
			1
		)
	},
		1
	);
}

void DIALOGO_inizializatuAmazoniarManati(struct Dialogo** dialogo)
{
	*dialogo = DIALOGO_sortu(
		"",
		"Kaixo! Zer behar duzu?",
		(struct Dialogo* []) {
		DIALOGO_sortu(
			"Kaixo! Erreportaia bat egiten ari naiz. Mesedez azaldu nor zaren.",
			"Ados! Ni amazoniar manati bat naiz, eta bost manatien taldean bizi nintzen, baina nire taldekideak ehizatuak izan dira.",
			(struct Dialogo* []) {
			DIALOGO_sortu(
				"Ze triste! Ehizariak oso arriskutsuak dira zuentzat?",
				"Bai. Gu espezie babestua gara habitatzen dugun herrialde guztietan, baina hala ere ehizatuak gara. Gure gorputzetatik abiatuta, hainbat produktu sortzen dira.",
				(struct Dialogo* []) {
				DIALOGO_sortu(
					"Zerbait egin dezakegu arrisku hori murrizteko?",
					"Eskatuko nizueke gizakiei, nondik datorren ez dakizuen produktu bat erosi baino lehen, galdetzea. Askotan ez dakizue nondik datozen produktuak, eta hori pena bat da.",
					(struct Dialogo* []) {
					DIALOGO_sortu(
						"Amaitzeko, zerbait gehiago esan nahi duzu?",
						"Bai. meatzaritza ilegalak hainbat produktu kaltegarri botatzen ditu uretara. Hori ekiditzeko, mesedez meatzaritza ilegala gelditu. Asko lagunduko luke.",
						(struct Dialogo* []) {
						DIALOGO_sortu(
							"Mila esker zure arretagatik! Agur!",
							"",
							(struct Dialogo* []) {
							0
						},
							0
						)
					},
						1
					),
						DIALOGO_sortu(
							"Mila esker zure arretagatik! Agur!",
							"",
							(struct Dialogo* []) {
						0,
					},
							0
						)
				},
					2
				)
			},
				1
			)
		},
			1
		)
	},
		1
	);
}


void DIALOGO_inizializatuBeluga(struct Dialogo** dialogo)
{
	*dialogo = DIALOGO_sortu(
		"",
		"Kaixo! beluga bat naiz eta Artikoko, Alaskako, Kanadako, Errusiako eta Groenlandiako itsasoetan bizi naiz baina gutxinaka nire espeziea desagertzer ari gara",
		(struct Dialogo* []) {
		DIALOGO_sortu(
			"Zer pasa ote da?",
			" Arrantza masiboagatik eta nire harrapariengatik, hartz polarrak eta orkak nagusiki, desagertzen ari naiz.",
			(struct Dialogo* []) {
			DIALOGO_sortu(
				"Baldago nik egin dezakeda ezer?",
				"Ehiza gutxitu beharko zen baina klima aldaketa eta kutsadura eragin handia dauka. Beraz faktore hauek gutxitzen saiatu.",
				(struct Dialogo* []) {
				DIALOGO_sortu(
					"Mila esker zure informazioa partekatzegatik, erreportaia horrela askoz garatuagoa egongo da!",
					"",
					(struct Dialogo* []) {
					0,
				},
					0
				)
			},
				1
			)
		},
			1
		)
	},
		1
	);

}

void DIALOGO_inizializatuBaleUrdin(struct Dialogo** dialogo)
{
	*dialogo = DIALOGO_sortu(
		"",
		"Kaixo! Zer moduz zaude? Zer behar duzu?",
		(struct Dialogo* []) {
		DIALOGO_sortu(
			"Ondo esan beharko. Erreportaia bat egiten ari naiz. Nor zara?",
			"Ni bale urdina naiz. Iraganean ugariak ginen, eta itsaso guztietan aurkitu gintzakezuen, baina gaur egun gutxi geratzen gara ehizaren ondorioz.",
			(struct Dialogo* []) {
			DIALOGO_sortu(
				"Ehiza arazo larria da zuentzat?",
				"Ez. Gaur egun, herrialde gehienek ehiza debekatzen dute eta gure poblazioa igotzen ari da. Gaur egun, gure arazo larriena itsasontziekin talkak dira",
				(struct Dialogo* []) {
				DIALOGO_sortu(
					"Mila esker zure arretagatik! Agur!",
					"",
					(struct Dialogo* []) {
					0,
				},
					0
				)
			},
				1
			)
		},
			1
		),
			DIALOGO_sortu(
				"Ondo. Erreportaia bat egiten ari naiz. Nor zara?",
				" Ni bale urdina naiz. Iraganean ugariak ginen, eta itsaso guztietan aurkitu gintzakezuen, baina gaur egun gutxi geratzen gara ehizaren ondorioz.",
				(struct Dialogo* []) {
			DIALOGO_sortu(
				"Ehiza arazo larria da zuentzat?",
				"Ez. Gaur egun, herrialde gehienek ehiza debekatzen dute eta gure poblazioa igotzen ari da. Gaur egun, gure arazo larriena itsasontziekin talkak dira",
				(struct Dialogo* []) {
				DIALOGO_sortu(
					"Mila esker zure arretagatik! Agur!",
					"",
					(struct Dialogo* []) {
					0,
				},
					0
				)
			},
				1
			)
		},
				1
			),
	},
		2
	);

}



void DIALOGO_inizializatuHartzTxuri(struct Dialogo** dialogo)
{
	*dialogo = DIALOGO_sortu(
		"",
		"Kaixo, zein zara",
		(struct Dialogo* [])
	{
		DIALOGO_sortu(
			"Kaixo, erreportai bat naiz, eta informazioa behar dut, galdera batzuk erantzun ahal dizkidazu?",
			"Hartz txuri  bat naiz eta Artikoan bizi naiz, zehazki, izotzen estalitako uretan",
			(struct Dialogo* [])
		{
			DIALOGO_sortu(
				"Zein da zuen mehatxu naguesiena??",
				" Kezkatuta nago klima-aldaketagatik. Izotzak urtzen ari dira eta nire habitata suntsitzen. Honen erruz, hiltzen ari gara eta desagertzear gaude.",
				(struct Dialogo* [])
			{
				DIALOGO_sortu(
					"Zer pasako litzake espeziea desagertuz gero?",
					" berotze-globala gero eta handiagoa izango da eta klima-aldaketaren ondorioak mundu osoan areagotzea lor dezake",
					(struct Dialogo* [])
				{
					DIALOGO_sortu(
						"Miyesker!",
						"",
						(struct Dialogo* [])
					{
						0,
					},
						0
					)
				},
					1
				)
			},
				1
			)
		},
			1
		)
	},
		1
	);
}

void DIALOGO_inizializatuLemur(struct Dialogo** dialogo)
{
	*dialogo = DIALOGO_sortu(
		"",
		"Kaixo! Zer moduz zaude? Zer behar duzu?",
		(struct Dialogo* []) {
		DIALOGO_sortu(
			"Kaixo, ni Kaxildo erreportaia naiz eta desagertzeko zorian dauden animaliei buruzko erreportai bat garatzen ari  naiz, horretarako hainbat galdera egin ditazket?",
			"Noski, lemur bat naiz eta Madagascar uhartean bizi naiz. ",
			(struct Dialogo* []) {
			DIALOGO_sortu(
				"Zein da desagertzearen ondorio nagusia?",
				"Etxeko animalia gisa nahi gaituzte bakardadeari aurre egin edo nirekin jolas dezaten. Beraz, ehizatu egiten gaituzte",
				(struct Dialogo* []) {
				DIALOGO_sortu(
					"Zer gertatuko litzake espezie hau desagertuz gero?",
					"Gu desagertuz gero, landare-espezie asko desager daitezke, guk sakabamatzen baititugu uhartean zehar landare haziak.",
					(struct Dialogo* []) {
					DIALOGO_sortu(
						"Mila esker zure arretagatik! Agur!",
						"",
						(struct Dialogo* []) {
						0,
					},
						0
					)
				},
					1
				)
			},
				1
			)
		},
			1
		),
			DIALOGO_sortu(
				"Ondo. Erreportaia bat egiten ari naiz. Nor zara?",
				" Ni, lemur bat naiz eta Madagascar uhartean bizi naiz.",
				(struct Dialogo* []) {
			DIALOGO_sortu(
				"Espezie guztiak daude arriskuan? ",
				"103 lemur espezie mehatxatuta daude, eta desagertzeko arrisku kritikoan 33 espezie daude",
				(struct Dialogo* []) {
				DIALOGO_sortu(
					"Zein punturaino zaudete arriskuan?",
					"Espezie hau %95 murriztu da eta 2.000 banako inguru baino ez dira geratzen beren habitat naturalean bizitzen.",
					(struct Dialogo* []) {
					DIALOGO_sortu(
						"Zuen ondorio nagusia zein da?",
						"Etxeko animalia gisa nahi gaituzte bakardadeari aurre egin edo nirekin jolas dezaten. Beraz, ehizatu egiten gaituzte",
						(struct Dialogo* []) {
						DIALOGO_sortu(
							"Mila esker, erantzunengatik",
							"",
							(struct Dialogo* []) {
							0,
						},
							0
						)

					},
						1
					)
				},
					1
				)
			},
				1
			)
		},
				1
			)
	},
		2
	);

	}


void DIALOGO_inizializatuAzeriArtiko(struct Dialogo** dialogo)
{
	*dialogo = DIALOGO_sortu(
		"",
		"Kaixo, zer nahi duzu?",
		(struct Dialogo* []) {
		DIALOGO_sortu(
			"Kaixo, erreportai bat naiz, eta informazioa behar dut, galdera batzuk erantzun ahal dizkidazu?",
			"Azari artiko bat naiz eta  Europako iparraldeko, Asiako eta Ipar Amerikako tundretan bizi naiz.",
			(struct Dialogo* []) {
			DIALOGO_sortu(
				"Zein da zuen arazoa?",
				" Desagertzen ari naiz hamsterren ugalketak gutxitzen ari direlako, horiek izaten baitira gure eguneroko elikadura.",
				(struct Dialogo* []) {
				DIALOGO_sortu(
					"Mehatsu gehiago badauzkazu?",
					"  Azari arruntak gure habitatarekin gelditzen ari dira ere eta honek ez digu mesederik egiten.",
					(struct Dialogo* []) {
					DIALOGO_sortu(
						"Nola konponduko zenuke arazoa? Zer egin dezakegu guk zuen espeziea mantentzeko? ",
						"Gu salbatzeko hamsterren ugalketa handitzea beharrezkoa da",
						(struct Dialogo* []) {
						DIALOGO_sortu(
							"Eskerrikasko!",
							"",
							(struct Dialogo* []) {
							0,
						},
							0
						)


					},
						1
					)
				},
					1
				)
			},
				1
			)
		},
			1
		)
	},
		1
	);

}


void DIALOGO_inizializatuJaguar(struct Dialogo** dialogo)
{
	*dialogo = DIALOGO_sortu(
		"",
		"Kaixo, zer nahi duzu?",
		(struct Dialogo* []) {
		DIALOGO_sortu(
			"Kaixo, erreportai bat egiten ari naiz eta informazioa behar dut, galdera batzuk erantzun ahal dizkidazu?",
			"Jaguarra naiz eta ekosistema desberdinetan bizitzeko gai naiz. Hala ere oihan baxu tropikalak eta mila metrotik beherako baso subtropikalak nahiago ditut.",
			(struct Dialogo* []) {
			DIALOGO_sortu(
				"Zein da zuen mehatsu nagusiena?",
				"Lurralde eremua da, hau da, lur handiak behar ditugu baina nekazaritza / abelzaintza jarduerekin eta bizitzeko eraikuntzekin zailtasunak edukitzen ditugu gure ekosistema apurtzen duelako.",
				(struct Dialogo* []) {
				DIALOGO_sortu(
					"Zer egin dezakegu arazo hau konpontzeko?",
					"Gure ekosistema babestu beharko litzake arreta handiagoz eta ehiza legalarekin bukatzea.",
					(struct Dialogo* []) {
					DIALOGO_sortu(
						"Eskerrikasko!",
						"",
						(struct Dialogo* []) {
						0,
					},
						0
					)

				},
					1
				)
			},
				1
			)
		},
			1
		)
	},
		1
	);

}