// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#include "yasl/core/locale.h"

#include "yasl/common/binding/class.h"
#include "yasl/common/binding/default_arguments.h"
#include "yasl/common/binding/namespace.h"
#include "yasl/common/enums.h"
#include "yasl/common/genericvarianthandler.h"
#include "yasl/common/listspecializations.h"
#include "yasl/core/flags.h"

#include "yasl/core/char.h"
#include "yasl/core/datastream.h"
#include "yasl/core/datetime.h"
#include "yasl/core/enums.h"
#include "yasl/core/locale.h"
#include "yasl/core/string.h"

#include <script/classbuilder.h>
#include <script/enumbuilder.h>

static void register_locale_language_enum(script::Class locale)
{
  using namespace script;

  Enum language = locale.newEnum("Language").setId(script::Type::QLocaleLanguage).get();

  language.addValue("AnyLanguage", QLocale::AnyLanguage);
  language.addValue("C", QLocale::C);
  language.addValue("Abkhazian", QLocale::Abkhazian);
  language.addValue("Oromo", QLocale::Oromo);
  language.addValue("Afar", QLocale::Afar);
  language.addValue("Afrikaans", QLocale::Afrikaans);
  language.addValue("Albanian", QLocale::Albanian);
  language.addValue("Amharic", QLocale::Amharic);
  language.addValue("Arabic", QLocale::Arabic);
  language.addValue("Armenian", QLocale::Armenian);
  language.addValue("Assamese", QLocale::Assamese);
  language.addValue("Aymara", QLocale::Aymara);
  language.addValue("Azerbaijani", QLocale::Azerbaijani);
  language.addValue("Bashkir", QLocale::Bashkir);
  language.addValue("Basque", QLocale::Basque);
  language.addValue("Bengali", QLocale::Bengali);
  language.addValue("Dzongkha", QLocale::Dzongkha);
  language.addValue("Bihari", QLocale::Bihari);
  language.addValue("Bislama", QLocale::Bislama);
  language.addValue("Breton", QLocale::Breton);
  language.addValue("Bulgarian", QLocale::Bulgarian);
  language.addValue("Burmese", QLocale::Burmese);
  language.addValue("Belarusian", QLocale::Belarusian);
  language.addValue("Khmer", QLocale::Khmer);
  language.addValue("Catalan", QLocale::Catalan);
  language.addValue("Chinese", QLocale::Chinese);
  language.addValue("Corsican", QLocale::Corsican);
  language.addValue("Croatian", QLocale::Croatian);
  language.addValue("Czech", QLocale::Czech);
  language.addValue("Danish", QLocale::Danish);
  language.addValue("Dutch", QLocale::Dutch);
  language.addValue("English", QLocale::English);
  language.addValue("Esperanto", QLocale::Esperanto);
  language.addValue("Estonian", QLocale::Estonian);
  language.addValue("Faroese", QLocale::Faroese);
  language.addValue("Fijian", QLocale::Fijian);
  language.addValue("Finnish", QLocale::Finnish);
  language.addValue("French", QLocale::French);
  language.addValue("WesternFrisian", QLocale::WesternFrisian);
  language.addValue("Gaelic", QLocale::Gaelic);
  language.addValue("Galician", QLocale::Galician);
  language.addValue("Georgian", QLocale::Georgian);
  language.addValue("German", QLocale::German);
  language.addValue("Greek", QLocale::Greek);
  language.addValue("Greenlandic", QLocale::Greenlandic);
  language.addValue("Guarani", QLocale::Guarani);
  language.addValue("Gujarati", QLocale::Gujarati);
  language.addValue("Hausa", QLocale::Hausa);
  language.addValue("Hebrew", QLocale::Hebrew);
  language.addValue("Hindi", QLocale::Hindi);
  language.addValue("Hungarian", QLocale::Hungarian);
  language.addValue("Icelandic", QLocale::Icelandic);
  language.addValue("Indonesian", QLocale::Indonesian);
  language.addValue("Interlingua", QLocale::Interlingua);
  language.addValue("Interlingue", QLocale::Interlingue);
  language.addValue("Inuktitut", QLocale::Inuktitut);
  language.addValue("Inupiak", QLocale::Inupiak);
  language.addValue("Irish", QLocale::Irish);
  language.addValue("Italian", QLocale::Italian);
  language.addValue("Japanese", QLocale::Japanese);
  language.addValue("Javanese", QLocale::Javanese);
  language.addValue("Kannada", QLocale::Kannada);
  language.addValue("Kashmiri", QLocale::Kashmiri);
  language.addValue("Kazakh", QLocale::Kazakh);
  language.addValue("Kinyarwanda", QLocale::Kinyarwanda);
  language.addValue("Kirghiz", QLocale::Kirghiz);
  language.addValue("Korean", QLocale::Korean);
  language.addValue("Kurdish", QLocale::Kurdish);
  language.addValue("Rundi", QLocale::Rundi);
  language.addValue("Lao", QLocale::Lao);
  language.addValue("Latin", QLocale::Latin);
  language.addValue("Latvian", QLocale::Latvian);
  language.addValue("Lingala", QLocale::Lingala);
  language.addValue("Lithuanian", QLocale::Lithuanian);
  language.addValue("Macedonian", QLocale::Macedonian);
  language.addValue("Malagasy", QLocale::Malagasy);
  language.addValue("Malay", QLocale::Malay);
  language.addValue("Malayalam", QLocale::Malayalam);
  language.addValue("Maltese", QLocale::Maltese);
  language.addValue("Maori", QLocale::Maori);
  language.addValue("Marathi", QLocale::Marathi);
  language.addValue("Marshallese", QLocale::Marshallese);
  language.addValue("Mongolian", QLocale::Mongolian);
  language.addValue("NauruLanguage", QLocale::NauruLanguage);
  language.addValue("Nepali", QLocale::Nepali);
  language.addValue("NorwegianBokmal", QLocale::NorwegianBokmal);
  language.addValue("Occitan", QLocale::Occitan);
  language.addValue("Oriya", QLocale::Oriya);
  language.addValue("Pashto", QLocale::Pashto);
  language.addValue("Persian", QLocale::Persian);
  language.addValue("Polish", QLocale::Polish);
  language.addValue("Portuguese", QLocale::Portuguese);
  language.addValue("Punjabi", QLocale::Punjabi);
  language.addValue("Quechua", QLocale::Quechua);
  language.addValue("Romansh", QLocale::Romansh);
  language.addValue("Romanian", QLocale::Romanian);
  language.addValue("Russian", QLocale::Russian);
  language.addValue("Samoan", QLocale::Samoan);
  language.addValue("Sango", QLocale::Sango);
  language.addValue("Sanskrit", QLocale::Sanskrit);
  language.addValue("Serbian", QLocale::Serbian);
  language.addValue("Ossetic", QLocale::Ossetic);
  language.addValue("SouthernSotho", QLocale::SouthernSotho);
  language.addValue("Tswana", QLocale::Tswana);
  language.addValue("Shona", QLocale::Shona);
  language.addValue("Sindhi", QLocale::Sindhi);
  language.addValue("Sinhala", QLocale::Sinhala);
  language.addValue("Swati", QLocale::Swati);
  language.addValue("Slovak", QLocale::Slovak);
  language.addValue("Slovenian", QLocale::Slovenian);
  language.addValue("Somali", QLocale::Somali);
  language.addValue("Spanish", QLocale::Spanish);
  language.addValue("Sundanese", QLocale::Sundanese);
  language.addValue("Swahili", QLocale::Swahili);
  language.addValue("Swedish", QLocale::Swedish);
  language.addValue("Sardinian", QLocale::Sardinian);
  language.addValue("Tajik", QLocale::Tajik);
  language.addValue("Tamil", QLocale::Tamil);
  language.addValue("Tatar", QLocale::Tatar);
  language.addValue("Telugu", QLocale::Telugu);
  language.addValue("Thai", QLocale::Thai);
  language.addValue("Tibetan", QLocale::Tibetan);
  language.addValue("Tigrinya", QLocale::Tigrinya);
  language.addValue("Tongan", QLocale::Tongan);
  language.addValue("Tsonga", QLocale::Tsonga);
  language.addValue("Turkish", QLocale::Turkish);
  language.addValue("Turkmen", QLocale::Turkmen);
  language.addValue("Tahitian", QLocale::Tahitian);
#if (QT_VERSION >= QT_VERSION_CHECK(5, 1, 0))
  language.addValue("Uighur", QLocale::Uighur);
#endif
  language.addValue("Ukrainian", QLocale::Ukrainian);
  language.addValue("Urdu", QLocale::Urdu);
  language.addValue("Uzbek", QLocale::Uzbek);
  language.addValue("Vietnamese", QLocale::Vietnamese);
  language.addValue("Volapuk", QLocale::Volapuk);
  language.addValue("Welsh", QLocale::Welsh);
  language.addValue("Wolof", QLocale::Wolof);
  language.addValue("Xhosa", QLocale::Xhosa);
  language.addValue("Yiddish", QLocale::Yiddish);
  language.addValue("Yoruba", QLocale::Yoruba);
  language.addValue("Zhuang", QLocale::Zhuang);
  language.addValue("Zulu", QLocale::Zulu);
  language.addValue("NorwegianNynorsk", QLocale::NorwegianNynorsk);
  language.addValue("Bosnian", QLocale::Bosnian);
  language.addValue("Divehi", QLocale::Divehi);
  language.addValue("Manx", QLocale::Manx);
  language.addValue("Cornish", QLocale::Cornish);
  language.addValue("Akan", QLocale::Akan);
  language.addValue("Konkani", QLocale::Konkani);
  language.addValue("Ga", QLocale::Ga);
  language.addValue("Igbo", QLocale::Igbo);
  language.addValue("Kamba", QLocale::Kamba);
  language.addValue("Syriac", QLocale::Syriac);
  language.addValue("Blin", QLocale::Blin);
  language.addValue("Geez", QLocale::Geez);
  language.addValue("Koro", QLocale::Koro);
  language.addValue("Sidamo", QLocale::Sidamo);
  language.addValue("Atsam", QLocale::Atsam);
  language.addValue("Tigre", QLocale::Tigre);
  language.addValue("Jju", QLocale::Jju);
  language.addValue("Friulian", QLocale::Friulian);
  language.addValue("Venda", QLocale::Venda);
  language.addValue("Ewe", QLocale::Ewe);
  language.addValue("Walamo", QLocale::Walamo);
  language.addValue("Hawaiian", QLocale::Hawaiian);
  language.addValue("Tyap", QLocale::Tyap);
  language.addValue("Nyanja", QLocale::Nyanja);
  language.addValue("Filipino", QLocale::Filipino);
  language.addValue("SwissGerman", QLocale::SwissGerman);
  language.addValue("SichuanYi", QLocale::SichuanYi);
  language.addValue("Kpelle", QLocale::Kpelle);
  language.addValue("LowGerman", QLocale::LowGerman);
  language.addValue("SouthNdebele", QLocale::SouthNdebele);
  language.addValue("NorthernSotho", QLocale::NorthernSotho);
  language.addValue("NorthernSami", QLocale::NorthernSami);
  language.addValue("Taroko", QLocale::Taroko);
  language.addValue("Gusii", QLocale::Gusii);
  language.addValue("Taita", QLocale::Taita);
  language.addValue("Fulah", QLocale::Fulah);
  language.addValue("Kikuyu", QLocale::Kikuyu);
  language.addValue("Samburu", QLocale::Samburu);
  language.addValue("Sena", QLocale::Sena);
  language.addValue("NorthNdebele", QLocale::NorthNdebele);
  language.addValue("Rombo", QLocale::Rombo);
  language.addValue("Tachelhit", QLocale::Tachelhit);
  language.addValue("Kabyle", QLocale::Kabyle);
  language.addValue("Nyankole", QLocale::Nyankole);
  language.addValue("Bena", QLocale::Bena);
  language.addValue("Vunjo", QLocale::Vunjo);
  language.addValue("Bambara", QLocale::Bambara);
  language.addValue("Embu", QLocale::Embu);
  language.addValue("Cherokee", QLocale::Cherokee);
  language.addValue("Morisyen", QLocale::Morisyen);
  language.addValue("Makonde", QLocale::Makonde);
  language.addValue("Langi", QLocale::Langi);
  language.addValue("Ganda", QLocale::Ganda);
  language.addValue("Bemba", QLocale::Bemba);
  language.addValue("Kabuverdianu", QLocale::Kabuverdianu);
  language.addValue("Meru", QLocale::Meru);
  language.addValue("Kalenjin", QLocale::Kalenjin);
  language.addValue("Nama", QLocale::Nama);
  language.addValue("Machame", QLocale::Machame);
  language.addValue("Colognian", QLocale::Colognian);
  language.addValue("Masai", QLocale::Masai);
  language.addValue("Soga", QLocale::Soga);
  language.addValue("Luyia", QLocale::Luyia);
  language.addValue("Asu", QLocale::Asu);
  language.addValue("Teso", QLocale::Teso);
  language.addValue("Saho", QLocale::Saho);
  language.addValue("KoyraChiini", QLocale::KoyraChiini);
  language.addValue("Rwa", QLocale::Rwa);
  language.addValue("Luo", QLocale::Luo);
  language.addValue("Chiga", QLocale::Chiga);
  language.addValue("CentralMoroccoTamazight", QLocale::CentralMoroccoTamazight);
  language.addValue("KoyraboroSenni", QLocale::KoyraboroSenni);
  language.addValue("Shambala", QLocale::Shambala);
  language.addValue("Bodo", QLocale::Bodo);
  language.addValue("Avaric", QLocale::Avaric);
  language.addValue("Chamorro", QLocale::Chamorro);
  language.addValue("Chechen", QLocale::Chechen);
  language.addValue("Church", QLocale::Church);
  language.addValue("Chuvash", QLocale::Chuvash);
  language.addValue("Cree", QLocale::Cree);
  language.addValue("Haitian", QLocale::Haitian);
  language.addValue("Herero", QLocale::Herero);
  language.addValue("HiriMotu", QLocale::HiriMotu);
  language.addValue("Kanuri", QLocale::Kanuri);
  language.addValue("Komi", QLocale::Komi);
  language.addValue("Kongo", QLocale::Kongo);
  language.addValue("Kwanyama", QLocale::Kwanyama);
  language.addValue("Limburgish", QLocale::Limburgish);
  language.addValue("LubaKatanga", QLocale::LubaKatanga);
  language.addValue("Luxembourgish", QLocale::Luxembourgish);
  language.addValue("Navaho", QLocale::Navaho);
  language.addValue("Ndonga", QLocale::Ndonga);
  language.addValue("Ojibwa", QLocale::Ojibwa);
  language.addValue("Pali", QLocale::Pali);
  language.addValue("Walloon", QLocale::Walloon);
  language.addValue("Aghem", QLocale::Aghem);
  language.addValue("Basaa", QLocale::Basaa);
  language.addValue("Zarma", QLocale::Zarma);
  language.addValue("Duala", QLocale::Duala);
  language.addValue("JolaFonyi", QLocale::JolaFonyi);
  language.addValue("Ewondo", QLocale::Ewondo);
  language.addValue("Bafia", QLocale::Bafia);
  language.addValue("MakhuwaMeetto", QLocale::MakhuwaMeetto);
  language.addValue("Mundang", QLocale::Mundang);
  language.addValue("Kwasio", QLocale::Kwasio);
  language.addValue("Nuer", QLocale::Nuer);
  language.addValue("Sakha", QLocale::Sakha);
  language.addValue("Sangu", QLocale::Sangu);
  language.addValue("CongoSwahili", QLocale::CongoSwahili);
  language.addValue("Tasawaq", QLocale::Tasawaq);
  language.addValue("Vai", QLocale::Vai);
  language.addValue("Walser", QLocale::Walser);
  language.addValue("Yangben", QLocale::Yangben);
  language.addValue("Avestan", QLocale::Avestan);
  language.addValue("Asturian", QLocale::Asturian);
  language.addValue("Ngomba", QLocale::Ngomba);
  language.addValue("Kako", QLocale::Kako);
  language.addValue("Meta", QLocale::Meta);
  language.addValue("Ngiemboon", QLocale::Ngiemboon);
#if (QT_VERSION >= QT_VERSION_CHECK(5, 1, 0))
  language.addValue("Aragonese", QLocale::Aragonese);
#endif
#if (QT_VERSION >= QT_VERSION_CHECK(5, 1, 0))
  language.addValue("Akkadian", QLocale::Akkadian);
#endif
#if (QT_VERSION >= QT_VERSION_CHECK(5, 1, 0))
  language.addValue("AncientEgyptian", QLocale::AncientEgyptian);
#endif
#if (QT_VERSION >= QT_VERSION_CHECK(5, 1, 0))
  language.addValue("AncientGreek", QLocale::AncientGreek);
#endif
#if (QT_VERSION >= QT_VERSION_CHECK(5, 1, 0))
  language.addValue("Aramaic", QLocale::Aramaic);
#endif
#if (QT_VERSION >= QT_VERSION_CHECK(5, 1, 0))
  language.addValue("Balinese", QLocale::Balinese);
#endif
#if (QT_VERSION >= QT_VERSION_CHECK(5, 1, 0))
  language.addValue("Bamun", QLocale::Bamun);
#endif
#if (QT_VERSION >= QT_VERSION_CHECK(5, 1, 0))
  language.addValue("BatakToba", QLocale::BatakToba);
#endif
#if (QT_VERSION >= QT_VERSION_CHECK(5, 1, 0))
  language.addValue("Buginese", QLocale::Buginese);
#endif
#if (QT_VERSION >= QT_VERSION_CHECK(5, 1, 0))
  language.addValue("Buhid", QLocale::Buhid);
#endif
#if (QT_VERSION >= QT_VERSION_CHECK(5, 1, 0))
  language.addValue("Carian", QLocale::Carian);
#endif
#if (QT_VERSION >= QT_VERSION_CHECK(5, 1, 0))
  language.addValue("Chakma", QLocale::Chakma);
#endif
#if (QT_VERSION >= QT_VERSION_CHECK(5, 1, 0))
  language.addValue("ClassicalMandaic", QLocale::ClassicalMandaic);
#endif
#if (QT_VERSION >= QT_VERSION_CHECK(5, 1, 0))
  language.addValue("Coptic", QLocale::Coptic);
#endif
#if (QT_VERSION >= QT_VERSION_CHECK(5, 1, 0))
  language.addValue("Dogri", QLocale::Dogri);
#endif
#if (QT_VERSION >= QT_VERSION_CHECK(5, 1, 0))
  language.addValue("EasternCham", QLocale::EasternCham);
#endif
#if (QT_VERSION >= QT_VERSION_CHECK(5, 1, 0))
  language.addValue("EasternKayah", QLocale::EasternKayah);
#endif
#if (QT_VERSION >= QT_VERSION_CHECK(5, 1, 0))
  language.addValue("Etruscan", QLocale::Etruscan);
#endif
#if (QT_VERSION >= QT_VERSION_CHECK(5, 1, 0))
  language.addValue("Gothic", QLocale::Gothic);
#endif
#if (QT_VERSION >= QT_VERSION_CHECK(5, 1, 0))
  language.addValue("Hanunoo", QLocale::Hanunoo);
#endif
#if (QT_VERSION >= QT_VERSION_CHECK(5, 1, 0))
  language.addValue("Ingush", QLocale::Ingush);
#endif
#if (QT_VERSION >= QT_VERSION_CHECK(5, 1, 0))
  language.addValue("LargeFloweryMiao", QLocale::LargeFloweryMiao);
#endif
#if (QT_VERSION >= QT_VERSION_CHECK(5, 1, 0))
  language.addValue("Lepcha", QLocale::Lepcha);
#endif
#if (QT_VERSION >= QT_VERSION_CHECK(5, 1, 0))
  language.addValue("Limbu", QLocale::Limbu);
#endif
#if (QT_VERSION >= QT_VERSION_CHECK(5, 1, 0))
  language.addValue("Lisu", QLocale::Lisu);
#endif
#if (QT_VERSION >= QT_VERSION_CHECK(5, 1, 0))
  language.addValue("Lu", QLocale::Lu);
#endif
#if (QT_VERSION >= QT_VERSION_CHECK(5, 1, 0))
  language.addValue("Lycian", QLocale::Lycian);
#endif
#if (QT_VERSION >= QT_VERSION_CHECK(5, 1, 0))
  language.addValue("Lydian", QLocale::Lydian);
#endif
#if (QT_VERSION >= QT_VERSION_CHECK(5, 1, 0))
  language.addValue("Mandingo", QLocale::Mandingo);
#endif
#if (QT_VERSION >= QT_VERSION_CHECK(5, 1, 0))
  language.addValue("Manipuri", QLocale::Manipuri);
#endif
#if (QT_VERSION >= QT_VERSION_CHECK(5, 1, 0))
  language.addValue("Meroitic", QLocale::Meroitic);
#endif
#if (QT_VERSION >= QT_VERSION_CHECK(5, 1, 0))
  language.addValue("NorthernThai", QLocale::NorthernThai);
#endif
#if (QT_VERSION >= QT_VERSION_CHECK(5, 1, 0))
  language.addValue("OldIrish", QLocale::OldIrish);
#endif
#if (QT_VERSION >= QT_VERSION_CHECK(5, 1, 0))
  language.addValue("OldNorse", QLocale::OldNorse);
#endif
#if (QT_VERSION >= QT_VERSION_CHECK(5, 1, 0))
  language.addValue("OldPersian", QLocale::OldPersian);
#endif
#if (QT_VERSION >= QT_VERSION_CHECK(5, 1, 0))
  language.addValue("OldTurkish", QLocale::OldTurkish);
#endif
#if (QT_VERSION >= QT_VERSION_CHECK(5, 1, 0))
  language.addValue("Pahlavi", QLocale::Pahlavi);
#endif
#if (QT_VERSION >= QT_VERSION_CHECK(5, 1, 0))
  language.addValue("Parthian", QLocale::Parthian);
#endif
#if (QT_VERSION >= QT_VERSION_CHECK(5, 1, 0))
  language.addValue("Phoenician", QLocale::Phoenician);
#endif
#if (QT_VERSION >= QT_VERSION_CHECK(5, 1, 0))
  language.addValue("PrakritLanguage", QLocale::PrakritLanguage);
#endif
#if (QT_VERSION >= QT_VERSION_CHECK(5, 1, 0))
  language.addValue("Rejang", QLocale::Rejang);
#endif
#if (QT_VERSION >= QT_VERSION_CHECK(5, 1, 0))
  language.addValue("Sabaean", QLocale::Sabaean);
#endif
#if (QT_VERSION >= QT_VERSION_CHECK(5, 1, 0))
  language.addValue("Samaritan", QLocale::Samaritan);
#endif
#if (QT_VERSION >= QT_VERSION_CHECK(5, 1, 0))
  language.addValue("Santali", QLocale::Santali);
#endif
#if (QT_VERSION >= QT_VERSION_CHECK(5, 1, 0))
  language.addValue("Saurashtra", QLocale::Saurashtra);
#endif
#if (QT_VERSION >= QT_VERSION_CHECK(5, 1, 0))
  language.addValue("Sora", QLocale::Sora);
#endif
#if (QT_VERSION >= QT_VERSION_CHECK(5, 1, 0))
  language.addValue("Sylheti", QLocale::Sylheti);
#endif
#if (QT_VERSION >= QT_VERSION_CHECK(5, 1, 0))
  language.addValue("Tagbanwa", QLocale::Tagbanwa);
#endif
#if (QT_VERSION >= QT_VERSION_CHECK(5, 1, 0))
  language.addValue("TaiDam", QLocale::TaiDam);
#endif
#if (QT_VERSION >= QT_VERSION_CHECK(5, 1, 0))
  language.addValue("TaiNua", QLocale::TaiNua);
#endif
#if (QT_VERSION >= QT_VERSION_CHECK(5, 1, 0))
  language.addValue("Ugaritic", QLocale::Ugaritic);
#endif
#if (QT_VERSION >= QT_VERSION_CHECK(5, 3, 0))
  language.addValue("Akoose", QLocale::Akoose);
#endif
#if (QT_VERSION >= QT_VERSION_CHECK(5, 3, 0))
  language.addValue("Lakota", QLocale::Lakota);
#endif
#if (QT_VERSION >= QT_VERSION_CHECK(5, 3, 0))
  language.addValue("StandardMoroccanTamazight", QLocale::StandardMoroccanTamazight);
#endif
#if (QT_VERSION >= QT_VERSION_CHECK(5, 5, 0))
  language.addValue("Mapuche", QLocale::Mapuche);
#endif
#if (QT_VERSION >= QT_VERSION_CHECK(5, 5, 0))
  language.addValue("CentralKurdish", QLocale::CentralKurdish);
#endif
#if (QT_VERSION >= QT_VERSION_CHECK(5, 5, 0))
  language.addValue("LowerSorbian", QLocale::LowerSorbian);
#endif
#if (QT_VERSION >= QT_VERSION_CHECK(5, 5, 0))
  language.addValue("UpperSorbian", QLocale::UpperSorbian);
#endif
#if (QT_VERSION >= QT_VERSION_CHECK(5, 5, 0))
  language.addValue("Kenyang", QLocale::Kenyang);
#endif
#if (QT_VERSION >= QT_VERSION_CHECK(5, 5, 0))
  language.addValue("Mohawk", QLocale::Mohawk);
#endif
#if (QT_VERSION >= QT_VERSION_CHECK(5, 5, 0))
  language.addValue("Nko", QLocale::Nko);
#endif
#if (QT_VERSION >= QT_VERSION_CHECK(5, 5, 0))
  language.addValue("Prussian", QLocale::Prussian);
#endif
#if (QT_VERSION >= QT_VERSION_CHECK(5, 5, 0))
  language.addValue("Kiche", QLocale::Kiche);
#endif
#if (QT_VERSION >= QT_VERSION_CHECK(5, 5, 0))
  language.addValue("SouthernSami", QLocale::SouthernSami);
#endif
#if (QT_VERSION >= QT_VERSION_CHECK(5, 5, 0))
  language.addValue("LuleSami", QLocale::LuleSami);
#endif
#if (QT_VERSION >= QT_VERSION_CHECK(5, 5, 0))
  language.addValue("InariSami", QLocale::InariSami);
#endif
#if (QT_VERSION >= QT_VERSION_CHECK(5, 5, 0))
  language.addValue("SkoltSami", QLocale::SkoltSami);
#endif
#if (QT_VERSION >= QT_VERSION_CHECK(5, 5, 0))
  language.addValue("Warlpiri", QLocale::Warlpiri);
#endif
#if (QT_VERSION >= QT_VERSION_CHECK(5, 5, 0))
  language.addValue("ManichaeanMiddlePersian", QLocale::ManichaeanMiddlePersian);
#endif
#if (QT_VERSION >= QT_VERSION_CHECK(5, 5, 0))
  language.addValue("Mende", QLocale::Mende);
#endif
#if (QT_VERSION >= QT_VERSION_CHECK(5, 5, 0))
  language.addValue("AncientNorthArabian", QLocale::AncientNorthArabian);
#endif
#if (QT_VERSION >= QT_VERSION_CHECK(5, 5, 0))
  language.addValue("LinearA", QLocale::LinearA);
#endif
#if (QT_VERSION >= QT_VERSION_CHECK(5, 5, 0))
  language.addValue("HmongNjua", QLocale::HmongNjua);
#endif
#if (QT_VERSION >= QT_VERSION_CHECK(5, 5, 0))
  language.addValue("Ho", QLocale::Ho);
#endif
#if (QT_VERSION >= QT_VERSION_CHECK(5, 5, 0))
  language.addValue("Lezghian", QLocale::Lezghian);
#endif
#if (QT_VERSION >= QT_VERSION_CHECK(5, 5, 0))
  language.addValue("Bassa", QLocale::Bassa);
#endif
#if (QT_VERSION >= QT_VERSION_CHECK(5, 5, 0))
  language.addValue("Mono", QLocale::Mono);
#endif
#if (QT_VERSION >= QT_VERSION_CHECK(5, 5, 0))
  language.addValue("TedimChin", QLocale::TedimChin);
#endif
#if (QT_VERSION >= QT_VERSION_CHECK(5, 5, 0))
  language.addValue("Maithili", QLocale::Maithili);
#endif
#if (QT_VERSION >= QT_VERSION_CHECK(5, 7, 0))
  language.addValue("Ahom", QLocale::Ahom);
#endif
#if (QT_VERSION >= QT_VERSION_CHECK(5, 7, 0))
  language.addValue("AmericanSignLanguage", QLocale::AmericanSignLanguage);
#endif
#if (QT_VERSION >= QT_VERSION_CHECK(5, 7, 0))
  language.addValue("ArdhamagadhiPrakrit", QLocale::ArdhamagadhiPrakrit);
#endif
#if (QT_VERSION >= QT_VERSION_CHECK(5, 7, 0))
  language.addValue("Bhojpuri", QLocale::Bhojpuri);
#endif
#if (QT_VERSION >= QT_VERSION_CHECK(5, 7, 0))
  language.addValue("HieroglyphicLuwian", QLocale::HieroglyphicLuwian);
#endif
#if (QT_VERSION >= QT_VERSION_CHECK(5, 7, 0))
  language.addValue("LiteraryChinese", QLocale::LiteraryChinese);
#endif
#if (QT_VERSION >= QT_VERSION_CHECK(5, 7, 0))
  language.addValue("Mazanderani", QLocale::Mazanderani);
#endif
#if (QT_VERSION >= QT_VERSION_CHECK(5, 7, 0))
  language.addValue("Mru", QLocale::Mru);
#endif
#if (QT_VERSION >= QT_VERSION_CHECK(5, 7, 0))
  language.addValue("Newari", QLocale::Newari);
#endif
#if (QT_VERSION >= QT_VERSION_CHECK(5, 7, 0))
  language.addValue("NorthernLuri", QLocale::NorthernLuri);
#endif
#if (QT_VERSION >= QT_VERSION_CHECK(5, 7, 0))
  language.addValue("Palauan", QLocale::Palauan);
#endif
#if (QT_VERSION >= QT_VERSION_CHECK(5, 7, 0))
  language.addValue("Papiamento", QLocale::Papiamento);
#endif
#if (QT_VERSION >= QT_VERSION_CHECK(5, 7, 0))
  language.addValue("Saraiki", QLocale::Saraiki);
#endif
#if (QT_VERSION >= QT_VERSION_CHECK(5, 7, 0))
  language.addValue("TokelauLanguage", QLocale::TokelauLanguage);
#endif
#if (QT_VERSION >= QT_VERSION_CHECK(5, 7, 0))
  language.addValue("TokPisin", QLocale::TokPisin);
#endif
#if (QT_VERSION >= QT_VERSION_CHECK(5, 7, 0))
  language.addValue("TuvaluLanguage", QLocale::TuvaluLanguage);
#endif
#if (QT_VERSION >= QT_VERSION_CHECK(5, 7, 0))
  language.addValue("UncodedLanguages", QLocale::UncodedLanguages);
#endif
#if (QT_VERSION >= QT_VERSION_CHECK(5, 7, 0))
  language.addValue("Cantonese", QLocale::Cantonese);
#endif
#if (QT_VERSION >= QT_VERSION_CHECK(5, 7, 0))
  language.addValue("Osage", QLocale::Osage);
#endif
#if (QT_VERSION >= QT_VERSION_CHECK(5, 7, 0))
  language.addValue("Tangut", QLocale::Tangut);
#endif
  language.addValue("Norwegian", QLocale::Norwegian);
  language.addValue("Moldavian", QLocale::Moldavian);
  language.addValue("SerboCroatian", QLocale::SerboCroatian);
  language.addValue("Tagalog", QLocale::Tagalog);
  language.addValue("Twi", QLocale::Twi);
  language.addValue("Afan", QLocale::Afan);
  language.addValue("Byelorussian", QLocale::Byelorussian);
  language.addValue("Bhutani", QLocale::Bhutani);
  language.addValue("Cambodian", QLocale::Cambodian);
  language.addValue("Kurundi", QLocale::Kurundi);
  language.addValue("RhaetoRomance", QLocale::RhaetoRomance);
  language.addValue("Chewa", QLocale::Chewa);
  language.addValue("Frisian", QLocale::Frisian);
  language.addValue("Uigur", QLocale::Uigur);
  language.addValue("LastLanguage", QLocale::LastLanguage);
}


static void register_locale_script_enum(script::Class locale)
{
  using namespace script;

  Enum script = locale.newEnum("Script").setId(script::Type::QLocaleScript).get();

  script.addValue("AnyScript", QLocale::AnyScript);
  script.addValue("ArabicScript", QLocale::ArabicScript);
  script.addValue("CyrillicScript", QLocale::CyrillicScript);
  script.addValue("DeseretScript", QLocale::DeseretScript);
  script.addValue("GurmukhiScript", QLocale::GurmukhiScript);
  script.addValue("SimplifiedHanScript", QLocale::SimplifiedHanScript);
  script.addValue("TraditionalHanScript", QLocale::TraditionalHanScript);
  script.addValue("LatinScript", QLocale::LatinScript);
  script.addValue("MongolianScript", QLocale::MongolianScript);
  script.addValue("TifinaghScript", QLocale::TifinaghScript);
  script.addValue("ArmenianScript", QLocale::ArmenianScript);
  script.addValue("BengaliScript", QLocale::BengaliScript);
  script.addValue("CherokeeScript", QLocale::CherokeeScript);
  script.addValue("DevanagariScript", QLocale::DevanagariScript);
  script.addValue("EthiopicScript", QLocale::EthiopicScript);
  script.addValue("GeorgianScript", QLocale::GeorgianScript);
  script.addValue("GreekScript", QLocale::GreekScript);
  script.addValue("GujaratiScript", QLocale::GujaratiScript);
  script.addValue("HebrewScript", QLocale::HebrewScript);
  script.addValue("JapaneseScript", QLocale::JapaneseScript);
  script.addValue("KhmerScript", QLocale::KhmerScript);
  script.addValue("KannadaScript", QLocale::KannadaScript);
  script.addValue("KoreanScript", QLocale::KoreanScript);
  script.addValue("LaoScript", QLocale::LaoScript);
  script.addValue("MalayalamScript", QLocale::MalayalamScript);
  script.addValue("MyanmarScript", QLocale::MyanmarScript);
  script.addValue("OriyaScript", QLocale::OriyaScript);
  script.addValue("TamilScript", QLocale::TamilScript);
  script.addValue("TeluguScript", QLocale::TeluguScript);
  script.addValue("ThaanaScript", QLocale::ThaanaScript);
  script.addValue("ThaiScript", QLocale::ThaiScript);
  script.addValue("TibetanScript", QLocale::TibetanScript);
  script.addValue("SinhalaScript", QLocale::SinhalaScript);
  script.addValue("SyriacScript", QLocale::SyriacScript);
  script.addValue("YiScript", QLocale::YiScript);
  script.addValue("VaiScript", QLocale::VaiScript);
#if (QT_VERSION >= QT_VERSION_CHECK(5, 1, 0))
  script.addValue("AvestanScript", QLocale::AvestanScript);
#endif
#if (QT_VERSION >= QT_VERSION_CHECK(5, 1, 0))
  script.addValue("BalineseScript", QLocale::BalineseScript);
#endif
#if (QT_VERSION >= QT_VERSION_CHECK(5, 1, 0))
  script.addValue("BamumScript", QLocale::BamumScript);
#endif
#if (QT_VERSION >= QT_VERSION_CHECK(5, 1, 0))
  script.addValue("BatakScript", QLocale::BatakScript);
#endif
#if (QT_VERSION >= QT_VERSION_CHECK(5, 1, 0))
  script.addValue("BopomofoScript", QLocale::BopomofoScript);
#endif
#if (QT_VERSION >= QT_VERSION_CHECK(5, 1, 0))
  script.addValue("BrahmiScript", QLocale::BrahmiScript);
#endif
#if (QT_VERSION >= QT_VERSION_CHECK(5, 1, 0))
  script.addValue("BugineseScript", QLocale::BugineseScript);
#endif
#if (QT_VERSION >= QT_VERSION_CHECK(5, 1, 0))
  script.addValue("BuhidScript", QLocale::BuhidScript);
#endif
#if (QT_VERSION >= QT_VERSION_CHECK(5, 1, 0))
  script.addValue("CanadianAboriginalScript", QLocale::CanadianAboriginalScript);
#endif
#if (QT_VERSION >= QT_VERSION_CHECK(5, 1, 0))
  script.addValue("CarianScript", QLocale::CarianScript);
#endif
#if (QT_VERSION >= QT_VERSION_CHECK(5, 1, 0))
  script.addValue("ChakmaScript", QLocale::ChakmaScript);
#endif
#if (QT_VERSION >= QT_VERSION_CHECK(5, 1, 0))
  script.addValue("ChamScript", QLocale::ChamScript);
#endif
#if (QT_VERSION >= QT_VERSION_CHECK(5, 1, 0))
  script.addValue("CopticScript", QLocale::CopticScript);
#endif
#if (QT_VERSION >= QT_VERSION_CHECK(5, 1, 0))
  script.addValue("CypriotScript", QLocale::CypriotScript);
#endif
#if (QT_VERSION >= QT_VERSION_CHECK(5, 1, 0))
  script.addValue("EgyptianHieroglyphsScript", QLocale::EgyptianHieroglyphsScript);
#endif
#if (QT_VERSION >= QT_VERSION_CHECK(5, 1, 0))
  script.addValue("FraserScript", QLocale::FraserScript);
#endif
#if (QT_VERSION >= QT_VERSION_CHECK(5, 1, 0))
  script.addValue("GlagoliticScript", QLocale::GlagoliticScript);
#endif
#if (QT_VERSION >= QT_VERSION_CHECK(5, 1, 0))
  script.addValue("GothicScript", QLocale::GothicScript);
#endif
#if (QT_VERSION >= QT_VERSION_CHECK(5, 1, 0))
  script.addValue("HanScript", QLocale::HanScript);
#endif
#if (QT_VERSION >= QT_VERSION_CHECK(5, 1, 0))
  script.addValue("HangulScript", QLocale::HangulScript);
#endif
#if (QT_VERSION >= QT_VERSION_CHECK(5, 1, 0))
  script.addValue("HanunooScript", QLocale::HanunooScript);
#endif
#if (QT_VERSION >= QT_VERSION_CHECK(5, 1, 0))
  script.addValue("ImperialAramaicScript", QLocale::ImperialAramaicScript);
#endif
#if (QT_VERSION >= QT_VERSION_CHECK(5, 1, 0))
  script.addValue("InscriptionalPahlaviScript", QLocale::InscriptionalPahlaviScript);
#endif
#if (QT_VERSION >= QT_VERSION_CHECK(5, 1, 0))
  script.addValue("InscriptionalParthianScript", QLocale::InscriptionalParthianScript);
#endif
#if (QT_VERSION >= QT_VERSION_CHECK(5, 1, 0))
  script.addValue("JavaneseScript", QLocale::JavaneseScript);
#endif
#if (QT_VERSION >= QT_VERSION_CHECK(5, 1, 0))
  script.addValue("KaithiScript", QLocale::KaithiScript);
#endif
#if (QT_VERSION >= QT_VERSION_CHECK(5, 1, 0))
  script.addValue("KatakanaScript", QLocale::KatakanaScript);
#endif
#if (QT_VERSION >= QT_VERSION_CHECK(5, 1, 0))
  script.addValue("KayahLiScript", QLocale::KayahLiScript);
#endif
#if (QT_VERSION >= QT_VERSION_CHECK(5, 1, 0))
  script.addValue("KharoshthiScript", QLocale::KharoshthiScript);
#endif
#if (QT_VERSION >= QT_VERSION_CHECK(5, 1, 0))
  script.addValue("LannaScript", QLocale::LannaScript);
#endif
#if (QT_VERSION >= QT_VERSION_CHECK(5, 1, 0))
  script.addValue("LepchaScript", QLocale::LepchaScript);
#endif
#if (QT_VERSION >= QT_VERSION_CHECK(5, 1, 0))
  script.addValue("LimbuScript", QLocale::LimbuScript);
#endif
#if (QT_VERSION >= QT_VERSION_CHECK(5, 1, 0))
  script.addValue("LinearBScript", QLocale::LinearBScript);
#endif
#if (QT_VERSION >= QT_VERSION_CHECK(5, 1, 0))
  script.addValue("LycianScript", QLocale::LycianScript);
#endif
#if (QT_VERSION >= QT_VERSION_CHECK(5, 1, 0))
  script.addValue("LydianScript", QLocale::LydianScript);
#endif
#if (QT_VERSION >= QT_VERSION_CHECK(5, 1, 0))
  script.addValue("MandaeanScript", QLocale::MandaeanScript);
#endif
#if (QT_VERSION >= QT_VERSION_CHECK(5, 1, 0))
  script.addValue("MeiteiMayekScript", QLocale::MeiteiMayekScript);
#endif
#if (QT_VERSION >= QT_VERSION_CHECK(5, 1, 0))
  script.addValue("MeroiticScript", QLocale::MeroiticScript);
#endif
#if (QT_VERSION >= QT_VERSION_CHECK(5, 1, 0))
  script.addValue("MeroiticCursiveScript", QLocale::MeroiticCursiveScript);
#endif
#if (QT_VERSION >= QT_VERSION_CHECK(5, 1, 0))
  script.addValue("NkoScript", QLocale::NkoScript);
#endif
#if (QT_VERSION >= QT_VERSION_CHECK(5, 1, 0))
  script.addValue("NewTaiLueScript", QLocale::NewTaiLueScript);
#endif
#if (QT_VERSION >= QT_VERSION_CHECK(5, 1, 0))
  script.addValue("OghamScript", QLocale::OghamScript);
#endif
#if (QT_VERSION >= QT_VERSION_CHECK(5, 1, 0))
  script.addValue("OlChikiScript", QLocale::OlChikiScript);
#endif
#if (QT_VERSION >= QT_VERSION_CHECK(5, 1, 0))
  script.addValue("OldItalicScript", QLocale::OldItalicScript);
#endif
#if (QT_VERSION >= QT_VERSION_CHECK(5, 1, 0))
  script.addValue("OldPersianScript", QLocale::OldPersianScript);
#endif
#if (QT_VERSION >= QT_VERSION_CHECK(5, 1, 0))
  script.addValue("OldSouthArabianScript", QLocale::OldSouthArabianScript);
#endif
#if (QT_VERSION >= QT_VERSION_CHECK(5, 1, 0))
  script.addValue("OrkhonScript", QLocale::OrkhonScript);
#endif
#if (QT_VERSION >= QT_VERSION_CHECK(5, 1, 0))
  script.addValue("OsmanyaScript", QLocale::OsmanyaScript);
#endif
#if (QT_VERSION >= QT_VERSION_CHECK(5, 1, 0))
  script.addValue("PhagsPaScript", QLocale::PhagsPaScript);
#endif
#if (QT_VERSION >= QT_VERSION_CHECK(5, 1, 0))
  script.addValue("PhoenicianScript", QLocale::PhoenicianScript);
#endif
#if (QT_VERSION >= QT_VERSION_CHECK(5, 1, 0))
  script.addValue("PollardPhoneticScript", QLocale::PollardPhoneticScript);
#endif
#if (QT_VERSION >= QT_VERSION_CHECK(5, 1, 0))
  script.addValue("RejangScript", QLocale::RejangScript);
#endif
#if (QT_VERSION >= QT_VERSION_CHECK(5, 1, 0))
  script.addValue("RunicScript", QLocale::RunicScript);
#endif
#if (QT_VERSION >= QT_VERSION_CHECK(5, 1, 0))
  script.addValue("SamaritanScript", QLocale::SamaritanScript);
#endif
#if (QT_VERSION >= QT_VERSION_CHECK(5, 1, 0))
  script.addValue("SaurashtraScript", QLocale::SaurashtraScript);
#endif
#if (QT_VERSION >= QT_VERSION_CHECK(5, 1, 0))
  script.addValue("SharadaScript", QLocale::SharadaScript);
#endif
#if (QT_VERSION >= QT_VERSION_CHECK(5, 1, 0))
  script.addValue("ShavianScript", QLocale::ShavianScript);
#endif
#if (QT_VERSION >= QT_VERSION_CHECK(5, 1, 0))
  script.addValue("SoraSompengScript", QLocale::SoraSompengScript);
#endif
#if (QT_VERSION >= QT_VERSION_CHECK(5, 1, 0))
  script.addValue("CuneiformScript", QLocale::CuneiformScript);
#endif
#if (QT_VERSION >= QT_VERSION_CHECK(5, 1, 0))
  script.addValue("SundaneseScript", QLocale::SundaneseScript);
#endif
#if (QT_VERSION >= QT_VERSION_CHECK(5, 1, 0))
  script.addValue("SylotiNagriScript", QLocale::SylotiNagriScript);
#endif
#if (QT_VERSION >= QT_VERSION_CHECK(5, 1, 0))
  script.addValue("TagalogScript", QLocale::TagalogScript);
#endif
#if (QT_VERSION >= QT_VERSION_CHECK(5, 1, 0))
  script.addValue("TagbanwaScript", QLocale::TagbanwaScript);
#endif
#if (QT_VERSION >= QT_VERSION_CHECK(5, 1, 0))
  script.addValue("TaiLeScript", QLocale::TaiLeScript);
#endif
#if (QT_VERSION >= QT_VERSION_CHECK(5, 1, 0))
  script.addValue("TaiVietScript", QLocale::TaiVietScript);
#endif
#if (QT_VERSION >= QT_VERSION_CHECK(5, 1, 0))
  script.addValue("TakriScript", QLocale::TakriScript);
#endif
#if (QT_VERSION >= QT_VERSION_CHECK(5, 1, 0))
  script.addValue("UgariticScript", QLocale::UgariticScript);
#endif
#if (QT_VERSION >= QT_VERSION_CHECK(5, 1, 0))
  script.addValue("BrailleScript", QLocale::BrailleScript);
#endif
#if (QT_VERSION >= QT_VERSION_CHECK(5, 1, 0))
  script.addValue("HiraganaScript", QLocale::HiraganaScript);
#endif
#if (QT_VERSION >= QT_VERSION_CHECK(5, 5, 0))
  script.addValue("CaucasianAlbanianScript", QLocale::CaucasianAlbanianScript);
#endif
#if (QT_VERSION >= QT_VERSION_CHECK(5, 5, 0))
  script.addValue("BassaVahScript", QLocale::BassaVahScript);
#endif
#if (QT_VERSION >= QT_VERSION_CHECK(5, 5, 0))
  script.addValue("DuployanScript", QLocale::DuployanScript);
#endif
#if (QT_VERSION >= QT_VERSION_CHECK(5, 5, 0))
  script.addValue("ElbasanScript", QLocale::ElbasanScript);
#endif
#if (QT_VERSION >= QT_VERSION_CHECK(5, 5, 0))
  script.addValue("GranthaScript", QLocale::GranthaScript);
#endif
#if (QT_VERSION >= QT_VERSION_CHECK(5, 5, 0))
  script.addValue("PahawhHmongScript", QLocale::PahawhHmongScript);
#endif
#if (QT_VERSION >= QT_VERSION_CHECK(5, 5, 0))
  script.addValue("KhojkiScript", QLocale::KhojkiScript);
#endif
#if (QT_VERSION >= QT_VERSION_CHECK(5, 5, 0))
  script.addValue("LinearAScript", QLocale::LinearAScript);
#endif
#if (QT_VERSION >= QT_VERSION_CHECK(5, 5, 0))
  script.addValue("MahajaniScript", QLocale::MahajaniScript);
#endif
#if (QT_VERSION >= QT_VERSION_CHECK(5, 5, 0))
  script.addValue("ManichaeanScript", QLocale::ManichaeanScript);
#endif
#if (QT_VERSION >= QT_VERSION_CHECK(5, 5, 0))
  script.addValue("MendeKikakuiScript", QLocale::MendeKikakuiScript);
#endif
#if (QT_VERSION >= QT_VERSION_CHECK(5, 5, 0))
  script.addValue("ModiScript", QLocale::ModiScript);
#endif
#if (QT_VERSION >= QT_VERSION_CHECK(5, 5, 0))
  script.addValue("MroScript", QLocale::MroScript);
#endif
#if (QT_VERSION >= QT_VERSION_CHECK(5, 5, 0))
  script.addValue("OldNorthArabianScript", QLocale::OldNorthArabianScript);
#endif
#if (QT_VERSION >= QT_VERSION_CHECK(5, 5, 0))
  script.addValue("NabataeanScript", QLocale::NabataeanScript);
#endif
#if (QT_VERSION >= QT_VERSION_CHECK(5, 5, 0))
  script.addValue("PalmyreneScript", QLocale::PalmyreneScript);
#endif
#if (QT_VERSION >= QT_VERSION_CHECK(5, 5, 0))
  script.addValue("PauCinHauScript", QLocale::PauCinHauScript);
#endif
#if (QT_VERSION >= QT_VERSION_CHECK(5, 5, 0))
  script.addValue("OldPermicScript", QLocale::OldPermicScript);
#endif
#if (QT_VERSION >= QT_VERSION_CHECK(5, 5, 0))
  script.addValue("PsalterPahlaviScript", QLocale::PsalterPahlaviScript);
#endif
#if (QT_VERSION >= QT_VERSION_CHECK(5, 5, 0))
  script.addValue("SiddhamScript", QLocale::SiddhamScript);
#endif
#if (QT_VERSION >= QT_VERSION_CHECK(5, 5, 0))
  script.addValue("KhudawadiScript", QLocale::KhudawadiScript);
#endif
#if (QT_VERSION >= QT_VERSION_CHECK(5, 5, 0))
  script.addValue("TirhutaScript", QLocale::TirhutaScript);
#endif
#if (QT_VERSION >= QT_VERSION_CHECK(5, 5, 0))
  script.addValue("VarangKshitiScript", QLocale::VarangKshitiScript);
#endif
#if (QT_VERSION >= QT_VERSION_CHECK(5, 7, 0))
  script.addValue("AhomScript", QLocale::AhomScript);
#endif
#if (QT_VERSION >= QT_VERSION_CHECK(5, 7, 0))
  script.addValue("AnatolianHieroglyphsScript", QLocale::AnatolianHieroglyphsScript);
#endif
#if (QT_VERSION >= QT_VERSION_CHECK(5, 7, 0))
  script.addValue("HatranScript", QLocale::HatranScript);
#endif
#if (QT_VERSION >= QT_VERSION_CHECK(5, 7, 0))
  script.addValue("MultaniScript", QLocale::MultaniScript);
#endif
#if (QT_VERSION >= QT_VERSION_CHECK(5, 7, 0))
  script.addValue("OldHungarianScript", QLocale::OldHungarianScript);
#endif
#if (QT_VERSION >= QT_VERSION_CHECK(5, 7, 0))
  script.addValue("SignWritingScript", QLocale::SignWritingScript);
#endif
#if (QT_VERSION >= QT_VERSION_CHECK(5, 7, 0))
  script.addValue("AdlamScript", QLocale::AdlamScript);
#endif
#if (QT_VERSION >= QT_VERSION_CHECK(5, 7, 0))
  script.addValue("BhaiksukiScript", QLocale::BhaiksukiScript);
#endif
#if (QT_VERSION >= QT_VERSION_CHECK(5, 7, 0))
  script.addValue("MarchenScript", QLocale::MarchenScript);
#endif
#if (QT_VERSION >= QT_VERSION_CHECK(5, 7, 0))
  script.addValue("NewaScript", QLocale::NewaScript);
#endif
#if (QT_VERSION >= QT_VERSION_CHECK(5, 7, 0))
  script.addValue("OsageScript", QLocale::OsageScript);
#endif
#if (QT_VERSION >= QT_VERSION_CHECK(5, 7, 0))
  script.addValue("TangutScript", QLocale::TangutScript);
#endif
#if (QT_VERSION >= QT_VERSION_CHECK(5, 7, 0))
  script.addValue("HanWithBopomofoScript", QLocale::HanWithBopomofoScript);
#endif
#if (QT_VERSION >= QT_VERSION_CHECK(5, 7, 0))
  script.addValue("JamoScript", QLocale::JamoScript);
#endif
  script.addValue("SimplifiedChineseScript", QLocale::SimplifiedChineseScript);
  script.addValue("TraditionalChineseScript", QLocale::TraditionalChineseScript);
  script.addValue("LastScript", QLocale::LastScript);
}


static void register_locale_country_enum(script::Class locale)
{
  using namespace script;

  Enum country = locale.newEnum("Country").setId(script::Type::QLocaleCountry).get();

  country.addValue("AnyCountry", QLocale::AnyCountry);
  country.addValue("Afghanistan", QLocale::Afghanistan);
  country.addValue("Albania", QLocale::Albania);
  country.addValue("Algeria", QLocale::Algeria);
  country.addValue("AmericanSamoa", QLocale::AmericanSamoa);
  country.addValue("Andorra", QLocale::Andorra);
  country.addValue("Angola", QLocale::Angola);
  country.addValue("Anguilla", QLocale::Anguilla);
  country.addValue("Antarctica", QLocale::Antarctica);
  country.addValue("AntiguaAndBarbuda", QLocale::AntiguaAndBarbuda);
  country.addValue("Argentina", QLocale::Argentina);
  country.addValue("Armenia", QLocale::Armenia);
  country.addValue("Aruba", QLocale::Aruba);
  country.addValue("Australia", QLocale::Australia);
  country.addValue("Austria", QLocale::Austria);
  country.addValue("Azerbaijan", QLocale::Azerbaijan);
  country.addValue("Bahamas", QLocale::Bahamas);
  country.addValue("Bahrain", QLocale::Bahrain);
  country.addValue("Bangladesh", QLocale::Bangladesh);
  country.addValue("Barbados", QLocale::Barbados);
  country.addValue("Belarus", QLocale::Belarus);
  country.addValue("Belgium", QLocale::Belgium);
  country.addValue("Belize", QLocale::Belize);
  country.addValue("Benin", QLocale::Benin);
  country.addValue("Bermuda", QLocale::Bermuda);
  country.addValue("Bhutan", QLocale::Bhutan);
  country.addValue("Bolivia", QLocale::Bolivia);
  country.addValue("BosniaAndHerzegowina", QLocale::BosniaAndHerzegowina);
  country.addValue("Botswana", QLocale::Botswana);
  country.addValue("BouvetIsland", QLocale::BouvetIsland);
  country.addValue("Brazil", QLocale::Brazil);
  country.addValue("BritishIndianOceanTerritory", QLocale::BritishIndianOceanTerritory);
  country.addValue("Brunei", QLocale::Brunei);
  country.addValue("Bulgaria", QLocale::Bulgaria);
  country.addValue("BurkinaFaso", QLocale::BurkinaFaso);
  country.addValue("Burundi", QLocale::Burundi);
  country.addValue("Cambodia", QLocale::Cambodia);
  country.addValue("Cameroon", QLocale::Cameroon);
  country.addValue("Canada", QLocale::Canada);
  country.addValue("CapeVerde", QLocale::CapeVerde);
  country.addValue("CaymanIslands", QLocale::CaymanIslands);
  country.addValue("CentralAfricanRepublic", QLocale::CentralAfricanRepublic);
  country.addValue("Chad", QLocale::Chad);
  country.addValue("Chile", QLocale::Chile);
  country.addValue("China", QLocale::China);
  country.addValue("ChristmasIsland", QLocale::ChristmasIsland);
  country.addValue("CocosIslands", QLocale::CocosIslands);
  country.addValue("Colombia", QLocale::Colombia);
  country.addValue("Comoros", QLocale::Comoros);
  country.addValue("CongoKinshasa", QLocale::CongoKinshasa);
  country.addValue("CongoBrazzaville", QLocale::CongoBrazzaville);
  country.addValue("CookIslands", QLocale::CookIslands);
  country.addValue("CostaRica", QLocale::CostaRica);
  country.addValue("IvoryCoast", QLocale::IvoryCoast);
  country.addValue("Croatia", QLocale::Croatia);
  country.addValue("Cuba", QLocale::Cuba);
  country.addValue("Cyprus", QLocale::Cyprus);
  country.addValue("CzechRepublic", QLocale::CzechRepublic);
  country.addValue("Denmark", QLocale::Denmark);
  country.addValue("Djibouti", QLocale::Djibouti);
  country.addValue("Dominica", QLocale::Dominica);
  country.addValue("DominicanRepublic", QLocale::DominicanRepublic);
  country.addValue("EastTimor", QLocale::EastTimor);
  country.addValue("Ecuador", QLocale::Ecuador);
  country.addValue("Egypt", QLocale::Egypt);
  country.addValue("ElSalvador", QLocale::ElSalvador);
  country.addValue("EquatorialGuinea", QLocale::EquatorialGuinea);
  country.addValue("Eritrea", QLocale::Eritrea);
  country.addValue("Estonia", QLocale::Estonia);
  country.addValue("Ethiopia", QLocale::Ethiopia);
  country.addValue("FalklandIslands", QLocale::FalklandIslands);
  country.addValue("FaroeIslands", QLocale::FaroeIslands);
  country.addValue("Fiji", QLocale::Fiji);
  country.addValue("Finland", QLocale::Finland);
  country.addValue("France", QLocale::France);
  country.addValue("Guernsey", QLocale::Guernsey);
  country.addValue("FrenchGuiana", QLocale::FrenchGuiana);
  country.addValue("FrenchPolynesia", QLocale::FrenchPolynesia);
  country.addValue("FrenchSouthernTerritories", QLocale::FrenchSouthernTerritories);
  country.addValue("Gabon", QLocale::Gabon);
  country.addValue("Gambia", QLocale::Gambia);
  country.addValue("Georgia", QLocale::Georgia);
  country.addValue("Germany", QLocale::Germany);
  country.addValue("Ghana", QLocale::Ghana);
  country.addValue("Gibraltar", QLocale::Gibraltar);
  country.addValue("Greece", QLocale::Greece);
  country.addValue("Greenland", QLocale::Greenland);
  country.addValue("Grenada", QLocale::Grenada);
  country.addValue("Guadeloupe", QLocale::Guadeloupe);
  country.addValue("Guam", QLocale::Guam);
  country.addValue("Guatemala", QLocale::Guatemala);
  country.addValue("Guinea", QLocale::Guinea);
  country.addValue("GuineaBissau", QLocale::GuineaBissau);
  country.addValue("Guyana", QLocale::Guyana);
  country.addValue("Haiti", QLocale::Haiti);
  country.addValue("HeardAndMcDonaldIslands", QLocale::HeardAndMcDonaldIslands);
  country.addValue("Honduras", QLocale::Honduras);
  country.addValue("HongKong", QLocale::HongKong);
  country.addValue("Hungary", QLocale::Hungary);
  country.addValue("Iceland", QLocale::Iceland);
  country.addValue("India", QLocale::India);
  country.addValue("Indonesia", QLocale::Indonesia);
  country.addValue("Iran", QLocale::Iran);
  country.addValue("Iraq", QLocale::Iraq);
  country.addValue("Ireland", QLocale::Ireland);
  country.addValue("Israel", QLocale::Israel);
  country.addValue("Italy", QLocale::Italy);
  country.addValue("Jamaica", QLocale::Jamaica);
  country.addValue("Japan", QLocale::Japan);
  country.addValue("Jordan", QLocale::Jordan);
  country.addValue("Kazakhstan", QLocale::Kazakhstan);
  country.addValue("Kenya", QLocale::Kenya);
  country.addValue("Kiribati", QLocale::Kiribati);
  country.addValue("NorthKorea", QLocale::NorthKorea);
  country.addValue("SouthKorea", QLocale::SouthKorea);
  country.addValue("Kuwait", QLocale::Kuwait);
  country.addValue("Kyrgyzstan", QLocale::Kyrgyzstan);
  country.addValue("Laos", QLocale::Laos);
  country.addValue("Latvia", QLocale::Latvia);
  country.addValue("Lebanon", QLocale::Lebanon);
  country.addValue("Lesotho", QLocale::Lesotho);
  country.addValue("Liberia", QLocale::Liberia);
  country.addValue("Libya", QLocale::Libya);
  country.addValue("Liechtenstein", QLocale::Liechtenstein);
  country.addValue("Lithuania", QLocale::Lithuania);
  country.addValue("Luxembourg", QLocale::Luxembourg);
  country.addValue("Macau", QLocale::Macau);
  country.addValue("Macedonia", QLocale::Macedonia);
  country.addValue("Madagascar", QLocale::Madagascar);
  country.addValue("Malawi", QLocale::Malawi);
  country.addValue("Malaysia", QLocale::Malaysia);
  country.addValue("Maldives", QLocale::Maldives);
  country.addValue("Mali", QLocale::Mali);
  country.addValue("Malta", QLocale::Malta);
  country.addValue("MarshallIslands", QLocale::MarshallIslands);
  country.addValue("Martinique", QLocale::Martinique);
  country.addValue("Mauritania", QLocale::Mauritania);
  country.addValue("Mauritius", QLocale::Mauritius);
  country.addValue("Mayotte", QLocale::Mayotte);
  country.addValue("Mexico", QLocale::Mexico);
  country.addValue("Micronesia", QLocale::Micronesia);
  country.addValue("Moldova", QLocale::Moldova);
  country.addValue("Monaco", QLocale::Monaco);
  country.addValue("Mongolia", QLocale::Mongolia);
  country.addValue("Montserrat", QLocale::Montserrat);
  country.addValue("Morocco", QLocale::Morocco);
  country.addValue("Mozambique", QLocale::Mozambique);
  country.addValue("Myanmar", QLocale::Myanmar);
  country.addValue("Namibia", QLocale::Namibia);
  country.addValue("NauruCountry", QLocale::NauruCountry);
  country.addValue("Nepal", QLocale::Nepal);
  country.addValue("Netherlands", QLocale::Netherlands);
  country.addValue("CuraSao", QLocale::CuraSao);
  country.addValue("NewCaledonia", QLocale::NewCaledonia);
  country.addValue("NewZealand", QLocale::NewZealand);
  country.addValue("Nicaragua", QLocale::Nicaragua);
  country.addValue("Niger", QLocale::Niger);
  country.addValue("Nigeria", QLocale::Nigeria);
  country.addValue("Niue", QLocale::Niue);
  country.addValue("NorfolkIsland", QLocale::NorfolkIsland);
  country.addValue("NorthernMarianaIslands", QLocale::NorthernMarianaIslands);
  country.addValue("Norway", QLocale::Norway);
  country.addValue("Oman", QLocale::Oman);
  country.addValue("Pakistan", QLocale::Pakistan);
  country.addValue("Palau", QLocale::Palau);
  country.addValue("PalestinianTerritories", QLocale::PalestinianTerritories);
  country.addValue("Panama", QLocale::Panama);
  country.addValue("PapuaNewGuinea", QLocale::PapuaNewGuinea);
  country.addValue("Paraguay", QLocale::Paraguay);
  country.addValue("Peru", QLocale::Peru);
  country.addValue("Philippines", QLocale::Philippines);
  country.addValue("Pitcairn", QLocale::Pitcairn);
  country.addValue("Poland", QLocale::Poland);
  country.addValue("Portugal", QLocale::Portugal);
  country.addValue("PuertoRico", QLocale::PuertoRico);
  country.addValue("Qatar", QLocale::Qatar);
  country.addValue("Reunion", QLocale::Reunion);
  country.addValue("Romania", QLocale::Romania);
  country.addValue("Russia", QLocale::Russia);
  country.addValue("Rwanda", QLocale::Rwanda);
  country.addValue("SaintKittsAndNevis", QLocale::SaintKittsAndNevis);
  country.addValue("SaintLucia", QLocale::SaintLucia);
  country.addValue("SaintVincentAndTheGrenadines", QLocale::SaintVincentAndTheGrenadines);
  country.addValue("Samoa", QLocale::Samoa);
  country.addValue("SanMarino", QLocale::SanMarino);
  country.addValue("SaoTomeAndPrincipe", QLocale::SaoTomeAndPrincipe);
  country.addValue("SaudiArabia", QLocale::SaudiArabia);
  country.addValue("Senegal", QLocale::Senegal);
  country.addValue("Seychelles", QLocale::Seychelles);
  country.addValue("SierraLeone", QLocale::SierraLeone);
  country.addValue("Singapore", QLocale::Singapore);
  country.addValue("Slovakia", QLocale::Slovakia);
  country.addValue("Slovenia", QLocale::Slovenia);
  country.addValue("SolomonIslands", QLocale::SolomonIslands);
  country.addValue("Somalia", QLocale::Somalia);
  country.addValue("SouthAfrica", QLocale::SouthAfrica);
  country.addValue("SouthGeorgiaAndTheSouthSandwichIslands", QLocale::SouthGeorgiaAndTheSouthSandwichIslands);
  country.addValue("Spain", QLocale::Spain);
  country.addValue("SriLanka", QLocale::SriLanka);
  country.addValue("SaintHelena", QLocale::SaintHelena);
  country.addValue("SaintPierreAndMiquelon", QLocale::SaintPierreAndMiquelon);
  country.addValue("Sudan", QLocale::Sudan);
  country.addValue("Suriname", QLocale::Suriname);
  country.addValue("SvalbardAndJanMayenIslands", QLocale::SvalbardAndJanMayenIslands);
  country.addValue("Swaziland", QLocale::Swaziland);
  country.addValue("Sweden", QLocale::Sweden);
  country.addValue("Switzerland", QLocale::Switzerland);
  country.addValue("Syria", QLocale::Syria);
  country.addValue("Taiwan", QLocale::Taiwan);
  country.addValue("Tajikistan", QLocale::Tajikistan);
  country.addValue("Tanzania", QLocale::Tanzania);
  country.addValue("Thailand", QLocale::Thailand);
  country.addValue("Togo", QLocale::Togo);
#if (QT_VERSION >= QT_VERSION_CHECK(5, 7, 0))
  country.addValue("TokelauCountry", QLocale::TokelauCountry);
#endif
  country.addValue("Tonga", QLocale::Tonga);
  country.addValue("TrinidadAndTobago", QLocale::TrinidadAndTobago);
  country.addValue("Tunisia", QLocale::Tunisia);
  country.addValue("Turkey", QLocale::Turkey);
  country.addValue("Turkmenistan", QLocale::Turkmenistan);
  country.addValue("TurksAndCaicosIslands", QLocale::TurksAndCaicosIslands);
#if (QT_VERSION >= QT_VERSION_CHECK(5, 7, 0))
  country.addValue("TuvaluCountry", QLocale::TuvaluCountry);
#endif
  country.addValue("Uganda", QLocale::Uganda);
  country.addValue("Ukraine", QLocale::Ukraine);
  country.addValue("UnitedArabEmirates", QLocale::UnitedArabEmirates);
  country.addValue("UnitedKingdom", QLocale::UnitedKingdom);
  country.addValue("UnitedStates", QLocale::UnitedStates);
  country.addValue("UnitedStatesMinorOutlyingIslands", QLocale::UnitedStatesMinorOutlyingIslands);
  country.addValue("Uruguay", QLocale::Uruguay);
  country.addValue("Uzbekistan", QLocale::Uzbekistan);
  country.addValue("Vanuatu", QLocale::Vanuatu);
  country.addValue("VaticanCityState", QLocale::VaticanCityState);
  country.addValue("Venezuela", QLocale::Venezuela);
  country.addValue("Vietnam", QLocale::Vietnam);
  country.addValue("BritishVirginIslands", QLocale::BritishVirginIslands);
  country.addValue("UnitedStatesVirginIslands", QLocale::UnitedStatesVirginIslands);
  country.addValue("WallisAndFutunaIslands", QLocale::WallisAndFutunaIslands);
  country.addValue("WesternSahara", QLocale::WesternSahara);
  country.addValue("Yemen", QLocale::Yemen);
  country.addValue("CanaryIslands", QLocale::CanaryIslands);
  country.addValue("Zambia", QLocale::Zambia);
  country.addValue("Zimbabwe", QLocale::Zimbabwe);
  country.addValue("ClippertonIsland", QLocale::ClippertonIsland);
  country.addValue("Montenegro", QLocale::Montenegro);
  country.addValue("Serbia", QLocale::Serbia);
  country.addValue("SaintBarthelemy", QLocale::SaintBarthelemy);
  country.addValue("SaintMartin", QLocale::SaintMartin);
  country.addValue("LatinAmericaAndTheCaribbean", QLocale::LatinAmericaAndTheCaribbean);
  country.addValue("AscensionIsland", QLocale::AscensionIsland);
  country.addValue("AlandIslands", QLocale::AlandIslands);
  country.addValue("DiegoGarcia", QLocale::DiegoGarcia);
  country.addValue("CeutaAndMelilla", QLocale::CeutaAndMelilla);
  country.addValue("IsleOfMan", QLocale::IsleOfMan);
  country.addValue("Jersey", QLocale::Jersey);
  country.addValue("TristanDaCunha", QLocale::TristanDaCunha);
  country.addValue("SouthSudan", QLocale::SouthSudan);
  country.addValue("Bonaire", QLocale::Bonaire);
  country.addValue("SintMaarten", QLocale::SintMaarten);
#if (QT_VERSION >= QT_VERSION_CHECK(5, 2, 0))
  country.addValue("Kosovo", QLocale::Kosovo);
#endif
#if (QT_VERSION >= QT_VERSION_CHECK(5, 7, 0))
  country.addValue("EuropeanUnion", QLocale::EuropeanUnion);
#endif
#if (QT_VERSION >= QT_VERSION_CHECK(5, 7, 0))
  country.addValue("OutlyingOceania", QLocale::OutlyingOceania);
#endif
  country.addValue("Tokelau", QLocale::Tokelau);
  country.addValue("Tuvalu", QLocale::Tuvalu);
  country.addValue("DemocraticRepublicOfCongo", QLocale::DemocraticRepublicOfCongo);
  country.addValue("PeoplesRepublicOfCongo", QLocale::PeoplesRepublicOfCongo);
  country.addValue("DemocraticRepublicOfKorea", QLocale::DemocraticRepublicOfKorea);
  country.addValue("RepublicOfKorea", QLocale::RepublicOfKorea);
  country.addValue("RussianFederation", QLocale::RussianFederation);
  country.addValue("SyrianArabRepublic", QLocale::SyrianArabRepublic);
  country.addValue("LastCountry", QLocale::LastCountry);
}


static void register_locale_measurement_system_enum(script::Class locale)
{
  using namespace script;

  Enum measurement_system = locale.newEnum("MeasurementSystem").setId(script::Type::QLocaleMeasurementSystem).get();

  measurement_system.addValue("MetricSystem", QLocale::MetricSystem);
  measurement_system.addValue("ImperialUSSystem", QLocale::ImperialUSSystem);
  measurement_system.addValue("ImperialUKSystem", QLocale::ImperialUKSystem);
  measurement_system.addValue("ImperialSystem", QLocale::ImperialSystem);
}


static void register_locale_format_type_enum(script::Class locale)
{
  using namespace script;

  Enum format_type = locale.newEnum("FormatType").setId(script::Type::QLocaleFormatType).get();

  format_type.addValue("LongFormat", QLocale::LongFormat);
  format_type.addValue("ShortFormat", QLocale::ShortFormat);
  format_type.addValue("NarrowFormat", QLocale::NarrowFormat);
}


static void register_locale_number_option_enum(script::Class locale)
{
  using namespace script;

  Enum number_option = locale.newEnum("NumberOption").setId(script::Type::QLocaleNumberOption).get();

  register_qflags_type<QLocale::NumberOption>(locale, "NumberOptions", script::Type::QLocaleNumberOptions);

#if (QT_VERSION >= QT_VERSION_CHECK(5, 7, 0))
  number_option.addValue("DefaultNumberOptions", QLocale::DefaultNumberOptions);
#endif
  number_option.addValue("OmitGroupSeparator", QLocale::OmitGroupSeparator);
  number_option.addValue("RejectGroupSeparator", QLocale::RejectGroupSeparator);
#if (QT_VERSION >= QT_VERSION_CHECK(5, 7, 0))
  number_option.addValue("OmitLeadingZeroInExponent", QLocale::OmitLeadingZeroInExponent);
#endif
#if (QT_VERSION >= QT_VERSION_CHECK(5, 7, 0))
  number_option.addValue("RejectLeadingZeroInExponent", QLocale::RejectLeadingZeroInExponent);
#endif
#if (QT_VERSION >= QT_VERSION_CHECK(5, 9, 0))
  number_option.addValue("IncludeTrailingZeroesAfterDot", QLocale::IncludeTrailingZeroesAfterDot);
#endif
#if (QT_VERSION >= QT_VERSION_CHECK(5, 9, 0))
  number_option.addValue("RejectTrailingZeroesAfterDot", QLocale::RejectTrailingZeroesAfterDot);
#endif
}


#if (QT_VERSION >= QT_VERSION_CHECK(5, 7, 0))
static void register_locale_floating_point_precision_option_enum(script::Class locale)
{
  using namespace script;

  Enum floating_point_precision_option = locale.newEnum("FloatingPointPrecisionOption").setId(script::Type::QLocaleFloatingPointPrecisionOption).get();

  floating_point_precision_option.addValue("FloatingPointShortest", QLocale::FloatingPointShortest);
}
#endif


static void register_locale_currency_symbol_format_enum(script::Class locale)
{
  using namespace script;

  Enum currency_symbol_format = locale.newEnum("CurrencySymbolFormat").setId(script::Type::QLocaleCurrencySymbolFormat).get();

  currency_symbol_format.addValue("CurrencyIsoCode", QLocale::CurrencyIsoCode);
  currency_symbol_format.addValue("CurrencySymbol", QLocale::CurrencySymbol);
  currency_symbol_format.addValue("CurrencyDisplayName", QLocale::CurrencyDisplayName);
}


#if (QT_VERSION >= QT_VERSION_CHECK(5, 10, 0))
static void register_locale_data_size_format_enum(script::Class locale)
{
  using namespace script;

  Enum data_size_format = locale.newEnum("DataSizeFormat").setId(script::Type::QLocaleDataSizeFormat).get();

  data_size_format.addValue("DataSizeBase1000", QLocale::DataSizeBase1000);
  data_size_format.addValue("DataSizeSIQuantifiers", QLocale::DataSizeSIQuantifiers);
  data_size_format.addValue("DataSizeIecFormat", QLocale::DataSizeIecFormat);
  data_size_format.addValue("DataSizeTraditionalFormat", QLocale::DataSizeTraditionalFormat);
  data_size_format.addValue("DataSizeSIFormat", QLocale::DataSizeSIFormat);
}
#endif


static void register_locale_quotation_style_enum(script::Class locale)
{
  using namespace script;

  Enum quotation_style = locale.newEnum("QuotationStyle").setId(script::Type::QLocaleQuotationStyle).get();

  quotation_style.addValue("StandardQuotation", QLocale::StandardQuotation);
  quotation_style.addValue("AlternateQuotation", QLocale::AlternateQuotation);
}


static void register_locale_class(script::Namespace ns)
{
  using namespace script;

  Class locale = ns.newClass("Locale").setId(script::Type::QLocale).get();

  register_proxy_specialization<QLocale>(locale.engine());
  register_list_specialization<QLocale>(locale.engine());
  register_locale_language_enum(locale);
  register_locale_script_enum(locale);
  register_locale_country_enum(locale);
  register_locale_measurement_system_enum(locale);
  register_locale_format_type_enum(locale);
  register_locale_number_option_enum(locale);
#if (QT_VERSION >= QT_VERSION_CHECK(5, 7, 0))
  register_locale_floating_point_precision_option_enum(locale);
#endif
  register_locale_currency_symbol_format_enum(locale);
#if (QT_VERSION >= QT_VERSION_CHECK(5, 10, 0))
  register_locale_data_size_format_enum(locale);
#endif
  register_locale_quotation_style_enum(locale);

  // QLocale();
  bind::default_constructor<QLocale>(locale).create();
  // QLocale(const QString &);
  bind::constructor<QLocale, const QString &>(locale).create();
  // QLocale(QLocale::Language, QLocale::Country = QLocale::AnyCountry);
  bind::constructor<QLocale, QLocale::Language, QLocale::Country>(locale)
    .apply(bind::default_arguments(QLocale::AnyCountry)).create();
  // QLocale(QLocale::Language, QLocale::Script, QLocale::Country);
  bind::constructor<QLocale, QLocale::Language, QLocale::Script, QLocale::Country>(locale).create();
  // QLocale(const QLocale &);
  bind::constructor<QLocale, const QLocale &>(locale).create();
  // QLocale & operator=(QLocale &&);
  bind::memop_assign<QLocale, QLocale &&>(locale);
  // QLocale & operator=(const QLocale &);
  bind::memop_assign<QLocale, const QLocale &>(locale);
  // ~QLocale();
  bind::destructor<QLocale>(locale).create();
#if (QT_VERSION >= QT_VERSION_CHECK(5, 7, 0))
  // void swap(QLocale &);
  bind::void_member_function<QLocale, QLocale &, &QLocale::swap>(locale, "swap").create();
#endif
  // QLocale::Language language() const;
  bind::member_function<QLocale, QLocale::Language, &QLocale::language>(locale, "language").create();
  // QLocale::Script script() const;
  bind::member_function<QLocale, QLocale::Script, &QLocale::script>(locale, "script").create();
  // QLocale::Country country() const;
  bind::member_function<QLocale, QLocale::Country, &QLocale::country>(locale, "country").create();
  // QString name() const;
  bind::member_function<QLocale, QString, &QLocale::name>(locale, "name").create();
  // QString bcp47Name() const;
  bind::member_function<QLocale, QString, &QLocale::bcp47Name>(locale, "bcp47Name").create();
  // QString nativeLanguageName() const;
  bind::member_function<QLocale, QString, &QLocale::nativeLanguageName>(locale, "nativeLanguageName").create();
  // QString nativeCountryName() const;
  bind::member_function<QLocale, QString, &QLocale::nativeCountryName>(locale, "nativeCountryName").create();
  // short toShort(const QString &, bool *) const;
  /// TODO: short toShort(const QString &, bool *) const;
  // ushort toUShort(const QString &, bool *) const;
  /// TODO: ushort toUShort(const QString &, bool *) const;
  // int toInt(const QString &, bool *) const;
  /// TODO: int toInt(const QString &, bool *) const;
  // uint toUInt(const QString &, bool *) const;
  /// TODO: uint toUInt(const QString &, bool *) const;
  // qlonglong toLongLong(const QString &, bool *) const;
  /// TODO: qlonglong toLongLong(const QString &, bool *) const;
  // qulonglong toULongLong(const QString &, bool *) const;
  /// TODO: qulonglong toULongLong(const QString &, bool *) const;
  // float toFloat(const QString &, bool *) const;
  /// TODO: float toFloat(const QString &, bool *) const;
  // double toDouble(const QString &, bool *) const;
  /// TODO: double toDouble(const QString &, bool *) const;
#if (QT_VERSION >= QT_VERSION_CHECK(5, 1, 0))
  // short toShort(const QStringRef &, bool *) const;
  /// TODO: short toShort(const QStringRef &, bool *) const;
#endif
#if (QT_VERSION >= QT_VERSION_CHECK(5, 1, 0))
  // ushort toUShort(const QStringRef &, bool *) const;
  /// TODO: ushort toUShort(const QStringRef &, bool *) const;
#endif
#if (QT_VERSION >= QT_VERSION_CHECK(5, 1, 0))
  // int toInt(const QStringRef &, bool *) const;
  /// TODO: int toInt(const QStringRef &, bool *) const;
#endif
#if (QT_VERSION >= QT_VERSION_CHECK(5, 1, 0))
  // uint toUInt(const QStringRef &, bool *) const;
  /// TODO: uint toUInt(const QStringRef &, bool *) const;
#endif
#if (QT_VERSION >= QT_VERSION_CHECK(5, 1, 0))
  // qlonglong toLongLong(const QStringRef &, bool *) const;
  /// TODO: qlonglong toLongLong(const QStringRef &, bool *) const;
#endif
#if (QT_VERSION >= QT_VERSION_CHECK(5, 1, 0))
  // qulonglong toULongLong(const QStringRef &, bool *) const;
  /// TODO: qulonglong toULongLong(const QStringRef &, bool *) const;
#endif
#if (QT_VERSION >= QT_VERSION_CHECK(5, 1, 0))
  // float toFloat(const QStringRef &, bool *) const;
  /// TODO: float toFloat(const QStringRef &, bool *) const;
#endif
#if (QT_VERSION >= QT_VERSION_CHECK(5, 1, 0))
  // double toDouble(const QStringRef &, bool *) const;
  /// TODO: double toDouble(const QStringRef &, bool *) const;
#endif
#if (QT_VERSION >= QT_VERSION_CHECK(5, 10, 0))
  // short toShort(QStringView, bool *) const;
  /// TODO: short toShort(QStringView, bool *) const;
#endif
#if (QT_VERSION >= QT_VERSION_CHECK(5, 10, 0))
  // ushort toUShort(QStringView, bool *) const;
  /// TODO: ushort toUShort(QStringView, bool *) const;
#endif
#if (QT_VERSION >= QT_VERSION_CHECK(5, 10, 0))
  // int toInt(QStringView, bool *) const;
  /// TODO: int toInt(QStringView, bool *) const;
#endif
#if (QT_VERSION >= QT_VERSION_CHECK(5, 10, 0))
  // uint toUInt(QStringView, bool *) const;
  /// TODO: uint toUInt(QStringView, bool *) const;
#endif
#if (QT_VERSION >= QT_VERSION_CHECK(5, 10, 0))
  // qlonglong toLongLong(QStringView, bool *) const;
  /// TODO: qlonglong toLongLong(QStringView, bool *) const;
#endif
#if (QT_VERSION >= QT_VERSION_CHECK(5, 10, 0))
  // qulonglong toULongLong(QStringView, bool *) const;
  /// TODO: qulonglong toULongLong(QStringView, bool *) const;
#endif
#if (QT_VERSION >= QT_VERSION_CHECK(5, 10, 0))
  // float toFloat(QStringView, bool *) const;
  /// TODO: float toFloat(QStringView, bool *) const;
#endif
#if (QT_VERSION >= QT_VERSION_CHECK(5, 10, 0))
  // double toDouble(QStringView, bool *) const;
  /// TODO: double toDouble(QStringView, bool *) const;
#endif
  // QString toString(qlonglong) const;
  /// TODO: QString toString(qlonglong) const;
  // QString toString(qulonglong) const;
  /// TODO: QString toString(qulonglong) const;
  // QString toString(short) const;
  /// TODO: QString toString(short) const;
  // QString toString(ushort) const;
  /// TODO: QString toString(ushort) const;
  // QString toString(int) const;
  bind::member_function<QLocale, QString, int, &QLocale::toString>(locale, "toString").create();
  // QString toString(uint) const;
  bind::member_function<QLocale, QString, uint, &QLocale::toString>(locale, "toString").create();
  // QString toString(double, char = 'g', int = 6) const;
  bind::member_function<QLocale, QString, double, char, int, &QLocale::toString>(locale, "toString")
    .apply(bind::default_arguments(6, 'g')).create();
  // QString toString(float, char = 'g', int = 6) const;
  bind::member_function<QLocale, QString, float, char, int, &QLocale::toString>(locale, "toString")
    .apply(bind::default_arguments(6, 'g')).create();
  // QString toString(const QDate &, const QString &) const;
  bind::member_function<QLocale, QString, const QDate &, const QString &, &QLocale::toString>(locale, "toString").create();
  // QString toString(const QTime &, const QString &) const;
  bind::member_function<QLocale, QString, const QTime &, const QString &, &QLocale::toString>(locale, "toString").create();
  // QString toString(const QDateTime &, const QString &) const;
  bind::member_function<QLocale, QString, const QDateTime &, const QString &, &QLocale::toString>(locale, "toString").create();
#if (QT_VERSION >= QT_VERSION_CHECK(5, 10, 0))
  // QString toString(const QDate &, QStringView) const;
  /// TODO: QString toString(const QDate &, QStringView) const;
#endif
#if (QT_VERSION >= QT_VERSION_CHECK(5, 10, 0))
  // QString toString(const QTime &, QStringView) const;
  /// TODO: QString toString(const QTime &, QStringView) const;
#endif
#if (QT_VERSION >= QT_VERSION_CHECK(5, 10, 0))
  // QString toString(const QDateTime &, QStringView) const;
  /// TODO: QString toString(const QDateTime &, QStringView) const;
#endif
  // QString toString(const QDate &, QLocale::FormatType) const;
  bind::member_function<QLocale, QString, const QDate &, QLocale::FormatType, &QLocale::toString>(locale, "toString").create();
  // QString toString(const QTime &, QLocale::FormatType) const;
  bind::member_function<QLocale, QString, const QTime &, QLocale::FormatType, &QLocale::toString>(locale, "toString").create();
  // QString toString(const QDateTime &, QLocale::FormatType) const;
  bind::member_function<QLocale, QString, const QDateTime &, QLocale::FormatType, &QLocale::toString>(locale, "toString").create();
  // QString dateFormat(QLocale::FormatType = QLocale::LongFormat) const;
  bind::member_function<QLocale, QString, QLocale::FormatType, &QLocale::dateFormat>(locale, "dateFormat")
    .apply(bind::default_arguments(QLocale::LongFormat)).create();
  // QString timeFormat(QLocale::FormatType = QLocale::LongFormat) const;
  bind::member_function<QLocale, QString, QLocale::FormatType, &QLocale::timeFormat>(locale, "timeFormat")
    .apply(bind::default_arguments(QLocale::LongFormat)).create();
  // QString dateTimeFormat(QLocale::FormatType = QLocale::LongFormat) const;
  bind::member_function<QLocale, QString, QLocale::FormatType, &QLocale::dateTimeFormat>(locale, "dateTimeFormat")
    .apply(bind::default_arguments(QLocale::LongFormat)).create();
  // QDate toDate(const QString &, QLocale::FormatType = QLocale::LongFormat) const;
  bind::member_function<QLocale, QDate, const QString &, QLocale::FormatType, &QLocale::toDate>(locale, "toDate")
    .apply(bind::default_arguments(QLocale::LongFormat)).create();
  // QTime toTime(const QString &, QLocale::FormatType = QLocale::LongFormat) const;
  bind::member_function<QLocale, QTime, const QString &, QLocale::FormatType, &QLocale::toTime>(locale, "toTime")
    .apply(bind::default_arguments(QLocale::LongFormat)).create();
  // QDateTime toDateTime(const QString &, QLocale::FormatType = QLocale::LongFormat) const;
  bind::member_function<QLocale, QDateTime, const QString &, QLocale::FormatType, &QLocale::toDateTime>(locale, "toDateTime")
    .apply(bind::default_arguments(QLocale::LongFormat)).create();
  // QDate toDate(const QString &, const QString &) const;
  bind::member_function<QLocale, QDate, const QString &, const QString &, &QLocale::toDate>(locale, "toDate").create();
  // QTime toTime(const QString &, const QString &) const;
  bind::member_function<QLocale, QTime, const QString &, const QString &, &QLocale::toTime>(locale, "toTime").create();
  // QDateTime toDateTime(const QString &, const QString &) const;
  bind::member_function<QLocale, QDateTime, const QString &, const QString &, &QLocale::toDateTime>(locale, "toDateTime").create();
  // QChar decimalPoint() const;
  bind::member_function<QLocale, QChar, &QLocale::decimalPoint>(locale, "decimalPoint").create();
  // QChar groupSeparator() const;
  bind::member_function<QLocale, QChar, &QLocale::groupSeparator>(locale, "groupSeparator").create();
  // QChar percent() const;
  bind::member_function<QLocale, QChar, &QLocale::percent>(locale, "percent").create();
  // QChar zeroDigit() const;
  bind::member_function<QLocale, QChar, &QLocale::zeroDigit>(locale, "zeroDigit").create();
  // QChar negativeSign() const;
  bind::member_function<QLocale, QChar, &QLocale::negativeSign>(locale, "negativeSign").create();
  // QChar positiveSign() const;
  bind::member_function<QLocale, QChar, &QLocale::positiveSign>(locale, "positiveSign").create();
  // QChar exponential() const;
  bind::member_function<QLocale, QChar, &QLocale::exponential>(locale, "exponential").create();
  // QString monthName(int, QLocale::FormatType = QLocale::LongFormat) const;
  bind::member_function<QLocale, QString, int, QLocale::FormatType, &QLocale::monthName>(locale, "monthName")
    .apply(bind::default_arguments(QLocale::LongFormat)).create();
  // QString standaloneMonthName(int, QLocale::FormatType = QLocale::LongFormat) const;
  bind::member_function<QLocale, QString, int, QLocale::FormatType, &QLocale::standaloneMonthName>(locale, "standaloneMonthName")
    .apply(bind::default_arguments(QLocale::LongFormat)).create();
  // QString dayName(int, QLocale::FormatType = QLocale::LongFormat) const;
  bind::member_function<QLocale, QString, int, QLocale::FormatType, &QLocale::dayName>(locale, "dayName")
    .apply(bind::default_arguments(QLocale::LongFormat)).create();
  // QString standaloneDayName(int, QLocale::FormatType = QLocale::LongFormat) const;
  bind::member_function<QLocale, QString, int, QLocale::FormatType, &QLocale::standaloneDayName>(locale, "standaloneDayName")
    .apply(bind::default_arguments(QLocale::LongFormat)).create();
  // Qt::DayOfWeek firstDayOfWeek() const;
  bind::member_function<QLocale, Qt::DayOfWeek, &QLocale::firstDayOfWeek>(locale, "firstDayOfWeek").create();
  // QList<Qt::DayOfWeek> weekdays() const;
  /// TODO: QList<Qt::DayOfWeek> weekdays() const;
  // QString amText() const;
  bind::member_function<QLocale, QString, &QLocale::amText>(locale, "amText").create();
  // QString pmText() const;
  bind::member_function<QLocale, QString, &QLocale::pmText>(locale, "pmText").create();
  // QLocale::MeasurementSystem measurementSystem() const;
  bind::member_function<QLocale, QLocale::MeasurementSystem, &QLocale::measurementSystem>(locale, "measurementSystem").create();
  // Qt::LayoutDirection textDirection() const;
  bind::member_function<QLocale, Qt::LayoutDirection, &QLocale::textDirection>(locale, "textDirection").create();
  // QString toUpper(const QString &) const;
  bind::member_function<QLocale, QString, const QString &, &QLocale::toUpper>(locale, "toUpper").create();
  // QString toLower(const QString &) const;
  bind::member_function<QLocale, QString, const QString &, &QLocale::toLower>(locale, "toLower").create();
  // QString currencySymbol(QLocale::CurrencySymbolFormat) const;
  bind::member_function<QLocale, QString, QLocale::CurrencySymbolFormat, &QLocale::currencySymbol>(locale, "currencySymbol").create();
  // QString toCurrencyString(qlonglong, const QString &) const;
  /// TODO: QString toCurrencyString(qlonglong, const QString &) const;
  // QString toCurrencyString(qulonglong, const QString &) const;
  /// TODO: QString toCurrencyString(qulonglong, const QString &) const;
  // QString toCurrencyString(short, const QString &) const;
  /// TODO: QString toCurrencyString(short, const QString &) const;
  // QString toCurrencyString(ushort, const QString &) const;
  /// TODO: QString toCurrencyString(ushort, const QString &) const;
  // QString toCurrencyString(int, const QString & = QString()) const;
  bind::member_function<QLocale, QString, int, const QString &, &QLocale::toCurrencyString>(locale, "toCurrencyString")
    .apply(bind::default_arguments(QString())).create();
  // QString toCurrencyString(uint, const QString &) const;
  bind::member_function<QLocale, QString, uint, const QString &, &QLocale::toCurrencyString>(locale, "toCurrencyString").create();
  // QString toCurrencyString(double, const QString & = QString()) const;
  bind::member_function<QLocale, QString, double, const QString &, &QLocale::toCurrencyString>(locale, "toCurrencyString")
    .apply(bind::default_arguments(QString())).create();
#if (QT_VERSION >= QT_VERSION_CHECK(5, 7, 0))
  // QString toCurrencyString(double, const QString &, int) const;
  bind::member_function<QLocale, QString, double, const QString &, int, &QLocale::toCurrencyString>(locale, "toCurrencyString").create();
#endif
#if (QT_VERSION >= QT_VERSION_CHECK(5, 7, 0))
  // QString toCurrencyString(float, const QString & = QString()) const;
  bind::member_function<QLocale, QString, float, const QString &, &QLocale::toCurrencyString>(locale, "toCurrencyString")
    .apply(bind::default_arguments(QString())).create();
#endif
#if (QT_VERSION >= QT_VERSION_CHECK(5, 7, 0))
  // QString toCurrencyString(float, const QString &, int) const;
  bind::member_function<QLocale, QString, float, const QString &, int, &QLocale::toCurrencyString>(locale, "toCurrencyString").create();
#endif
#if (QT_VERSION >= QT_VERSION_CHECK(5, 10, 0))
  // QString formattedDataSize(qint64, int = 2, QLocale::DataSizeFormats = QLocale::DataSizeIecFormat);
  /// TODO: QString formattedDataSize(qint64, int = 2, QLocale::DataSizeFormats = QLocale::DataSizeIecFormat);
#endif
  // QStringList uiLanguages() const;
  bind::member_function<QLocale, QStringList, &QLocale::uiLanguages>(locale, "uiLanguages").create();
  // bool operator==(const QLocale &) const;
  bind::memop_eq<QLocale, const QLocale &>(locale);
  // bool operator!=(const QLocale &) const;
  bind::memop_neq<QLocale, const QLocale &>(locale);
  // static QString languageToString(QLocale::Language);
  bind::static_member_function<QLocale, QString, QLocale::Language, &QLocale::languageToString>(locale, "languageToString").create();
  // static QString countryToString(QLocale::Country);
  bind::static_member_function<QLocale, QString, QLocale::Country, &QLocale::countryToString>(locale, "countryToString").create();
  // static QString scriptToString(QLocale::Script);
  bind::static_member_function<QLocale, QString, QLocale::Script, &QLocale::scriptToString>(locale, "scriptToString").create();
  // static void setDefault(const QLocale &);
  bind::static_void_member_function<QLocale, const QLocale &, &QLocale::setDefault>(locale, "setDefault").create();
  // static QLocale c();
  bind::static_member_function<QLocale, QLocale, &QLocale::c>(locale, "c").create();
  // static QLocale system();
  bind::static_member_function<QLocale, QLocale, &QLocale::system>(locale, "system").create();
  // static QList<QLocale> matchingLocales(QLocale::Language, QLocale::Script, QLocale::Country);
  bind::static_member_function<QLocale, QList<QLocale>, QLocale::Language, QLocale::Script, QLocale::Country, &QLocale::matchingLocales>(locale, "matchingLocales").create();
  // static QList<QLocale::Country> countriesForLanguage(QLocale::Language);
  /// TODO: static QList<QLocale::Country> countriesForLanguage(QLocale::Language);
  // void setNumberOptions(QLocale::NumberOptions);
  bind::void_member_function<QLocale, QLocale::NumberOptions, &QLocale::setNumberOptions>(locale, "setNumberOptions").create();
  // QLocale::NumberOptions numberOptions() const;
  bind::member_function<QLocale, QLocale::NumberOptions, &QLocale::numberOptions>(locale, "numberOptions").create();
  // QString quoteString(const QString &, QLocale::QuotationStyle = QLocale::StandardQuotation) const;
  bind::member_function<QLocale, QString, const QString &, QLocale::QuotationStyle, &QLocale::quoteString>(locale, "quoteString")
    .apply(bind::default_arguments(QLocale::StandardQuotation)).create();
  // QString quoteString(const QStringRef &, QLocale::QuotationStyle = QLocale::StandardQuotation) const;
  /// TODO: QString quoteString(const QStringRef &, QLocale::QuotationStyle = QLocale::StandardQuotation) const;
  // QString createSeparatedList(const QStringList &) const;
  bind::member_function<QLocale, QString, const QStringList &, &QLocale::createSeparatedList>(locale, "createSeparatedList").create();

  yasl::registerVariantHandler<yasl::GenericVariantHandler<QLocale, QMetaType::QLocale>>();
}


void register_locale_file(script::Namespace core)
{
  using namespace script;

  Namespace ns = core;

  register_locale_class(ns);

#if (QT_VERSION >= QT_VERSION_CHECK(5, 6, 0))
  // uint qHash(const QLocale &, uint);
  bind::function<uint, const QLocale &, uint, &qHash>(ns, "qHash").create();
#endif
  // QLocale::NumberOptions operator|(QLocale::NumberOption, QLocale::NumberOption);
  bind::op_bitor<QLocale::NumberOptions, QLocale::NumberOption, QLocale::NumberOption>(ns);
  // QLocale::NumberOptions operator|(QLocale::NumberOption, QLocale::NumberOptions);
  bind::op_bitor<QLocale::NumberOptions, QLocale::NumberOption, QLocale::NumberOptions>(ns);
  // QIncompatibleFlag operator|(QLocale::NumberOptions::enum_type, int);
  /// TODO: QIncompatibleFlag operator|(QLocale::NumberOptions::enum_type, int);
  // QDataStream & operator<<(QDataStream &, const QLocale &);
  bind::op_put_to<QDataStream &, const QLocale &>(ns);
  // QDataStream & operator>>(QDataStream &, QLocale &);
  bind::op_read_from<QDataStream &, QLocale &>(ns);
  // QDebug operator<<(QDebug, const QLocale &);
  /// TODO: QDebug operator<<(QDebug, const QLocale &);
}
