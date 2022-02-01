void ProcessDialogEvent()
{
	ref NPChar;
	aref Link, NextDiag;

	DeleteAttribute(&Dialog,"Links");

	makeref(NPChar,CharacterRef);
	makearef(Link, Dialog.Links);
	makearef(NextDiag, NPChar.Dialog);

// ============================================================================
// ============================= блок angry ==========>>>>>>>>>>>>>>>>>>>>>>>>>
    if (CheckAttribute(npchar, "angry") && !CheckAttribute(npchar, "angry.ok"))
    {
        npchar.angry.ok = 1;
        if (!CheckAttribute(npchar, "angry.first")) //ловушка первого срабатывания
        {
            NextDiag.TempNode = NextDiag.CurrentNode;
            Dialog.CurrentNode = "AngryExitAgain";
            npchar.angry.first = 1;
        }
        else
        {
			Dialog.CurrentNode = "AngryQuest";
        }
    }
// <<<<<<<<<<<<<<<<<<<<<<======= блок angry ===================================
// ============================================================================	
    
	switch(Dialog.CurrentNode)
	{
		// ----------------------------------- Диалог первый - первая встреча
		case "First time":
        	dialog.text = "Добрый день, " + GetFullName(pchar) + ". Свежий ветер, море... Мне нравится. Кажется, такое платье носят сейчас?";
    		link.l1 = "Да, платье в самый раз... Я же только что был"+ GetSexPhrase("","а") +" на верфи " + XI_ConvertString("Colony"+pchar.questTemp.Ascold.ShipyarderColony+"Gen") + "!!! Как я сюда попал"+ GetSexPhrase("","а") +"?! Черт возьми, что происходит?!!";
    		link.l1.go = "Step_1";
		break;

		case "Step_1":
        	dialog.text = "Не надо так волноваться.\n"+
                          "Во-первых, я не банальный черт, а демон! Взял тебя на время, сейчас поговорим и верну на место.\n"+
                          "А во-вторых, спасибо, что все-таки вскрыл"+ GetSexPhrase("","а") +" лампу.";
    		link.l1 = "Что?! Опять?!!!";
    		link.l1.go = "Step_2";
		break;

		case "Step_2":
        	dialog.text = "Это ты о Лейфе Эриксоне? Не переживай, я не буду заставлять тебя разыскивать для себя предметы и штурмовать города.\n"+
                          "Я проторчал в этой лампе очень много времени, у меня сейчас других дел полно.";
       		link.l1 = "А как насчет подмены тел? Этого ты тоже делать не будешь?";
    		link.l1.go = "Step_3";
		break;

		case "Step_3":
        	dialog.text = "Нет, не буду. Это запрещено циркуляром 15315/28. Да и зачем?";
    		link.l1 = "Уф, это радует... Слушай, так Лейф могущественней тебя, демона?";
    		link.l1.go = "Step_4";
		break;

		case "Step_4":
        	dialog.text = "Это почему ты так решил"+ GetSexPhrase("","а") +"? А-а-а, из-за того, что он дважды осуществил подмену тел?\n"+
                          "Я - демон, и не последний в нашей структуре. Я могу все, в том числе и дать тебе любое тело. Но циркуляр №15315/28 Контрольно-ревизионного Управления Ада не позволяет производить обмен телами без согласия на то смертного и оформления соответствующих документов.\n"+
                          "А Лейф - мелкий мошенник, нахватался индейских оккультных ритуалов и сумел вызвать меня. И что самое печальное - ему удалось меня обмануть, хотя я сам во всем виноват...";
    		link.l1 = "Как это? Извини, конечно, за вопрос, но очень интересно.";
    		link.l1.go = "Step_5";
		break;

		case "Step_5":
        	dialog.text = "Да нет проблем. Я к тебе испытываю определенное чувство благодарности, ты ведь вскрыл"+ GetSexPhrase("","а") +" эту жестянку и не отдал"+ GetSexPhrase("","а") +" ее церкви.\n"+
                          "Так вот, этот поганец Лейф к старости стал подумывать о том, как ему обрести бессмертие, а все дороги на пути к этой цели ведут в Ад.\n"+
                          "Лейф, к тому времени объездивший половину континента, ныне называемого Америкой, и побывавший в множестве местных племен, изучил довольно много сильных заклинаний. То есть стал добротным колдуном, в европейском понимании этого слова. Кстати, фокусу с переселением душ между двумя телами он научился у ацтеков.\n"+
                          "В Европе он тоже занимался мракобесием (не зря ему везло и прозвище у него было - Счастливый), поэтому знал, что если в момент смерти рядом находится демон, то душа не покидает тела для Страшного Суда.\n"+
                          "А у тольтеков Лейф нашел действенный ритуал вызова демонов. Он привел ритуал в действие и, к несчастью, вызвал именно меня.";
    		link.l1 = "Так как же ему удалось обмануть тебя, ведь демоны знают все!";
    		link.l1.go = "Step_6";
		break;

		case "Step_6":
        	dialog.text = "Знают, это верно. Но, понимаешь, мы используем данную процедуру вызова нас для получения души и тела смертного непосредственно в Ад, минуя канцелярию Страшного Суда.\n"+
                          "Смертных идиотов хватает, они пытаются заключить нас в подготовленную особым образом бутылку для того, чтобы мы выполняли их желания. Под клятву не закрывать бутылку в залог собственной души мы спокойно помещаемся внутрь, и через мгновение бутылка всегда оказывается закрытой.\n"+
                          "Смертные полагают, что дело в шляпе, но у каждого из нас на пальце есть алмазное кольцо, специально для таких случаев. Используя его в качестве стеклореза, мы освобождаемся и забираем душу с телом в придачу.";
    		link.l1 = "А Лейф использовал не бутылку, а жестянку...";
    		link.l1.go = "Step_7";
		break;

		case "Step_7":
        	dialog.text = "Точно. В такие жестянки помещают восточных демонов-рабов - джиннов. Лейф использовал лампу джинна для заточения меня.\n"+
                          "И надо же такому случится, что процедуру вызова он выполнил на следующий день после Вальпургиевой Ночи - моего любимого праздника на Земле.\n"+
                          "Я, как всегда, провел этот праздник чрезвычайно весело. Люблю, знаешь, земных девок подснимать, а готские ведьмы такие горячие-е-е-е.\n"+
                          "В общем, с похмелья даже и не увидел, куда лезу. Вот так и попался. А Лейф после моего заточения отправил письмо своим родственникам, где описал ритуал своего воскрешения. Это письмо и нашел француз де ла Фонтен, а ты привел"+ GetSexPhrase("","а") +" ритуал в действие.";
    		link.l1 = "Слушай, а твои собратья - демоны - не могли тебя освободить?";
    		link.l1.go = "Step_8";
		break;

		case "Step_8":
        	dialog.text = "Нет, я в это время не на службе был, бессрочный отпуск взял. А тех, кто болтается по Земле в поисках развлечений сам по себе, канцелярия Ада не очень-то жалует. Так что вляпался по самое не балуйся.";
    		link.l1 = "Да уж, даже не знаю, что и сказать...";
    		link.l1.go = "Step_9";
		break;

		case "Step_9":
        	dialog.text = "А что тут говорить, лопухнулся удалой демон Аззи, как последний земной лох.";
    		link.l1 = "О-о-о, так тебя зовут Аззи?! Очень приятно познакомится.";
    		link.l1.go = "Step_10";
		break;
		
		case "Step_10":
        	dialog.text = "Мне тоже. Учитывая то, что результатом знакомства стало мое освобождение, мне приятно вдвойне.\n"+
                          "Однако, теперь ты знаешь мое имя и можешь провести ритуал моего вызова. Надеюсь, ты не станешь дергать меня по поводу и без повода.\n"+
                          "Я, знаешь ли, очень этого не люблю. Так попадешь не в настроение, и мое хорошее отношение к тебе вмиг испарится. А в гневе я страшен...";
    		link.l1 = "Да я и ритуалов-то не знаю. Я в этом деле совершеннейш"+ GetSexPhrase("ий","ая") +" профан"+ GetSexPhrase("","ка") +". Это мне к тольтекам, что ли, бегать, у которых Лейф обряд раздобыл...";
    		link.l1.go = "Step_11";
		break;

		case "Step_11":
        	dialog.text = "Смотри сам"+ GetSexPhrase("","а") +", я тебе в этом деле точно помогать не стану. Все, что тебе нужно, вернее, все, что ты захочешь взять, я тебе дам сейчас.";
    		link.l1 = "Хм... Дары от нечистой силы? Скажу откровенно - я себе зла не желаю.";
    		link.l1.go = "Step_12";
		break;

		case "Step_12":
        	dialog.text = "Добро, зло... Две стороны одной медали.\n"+
                          "Зороастризм времен персидского царя Дария - первая религия в истории человечества, приблизившаяся к пониманию сути вещей, но и пророк Зороастр был весьма далек от истины.\n"+
                          "Добро и зло часто переплетаются настолько, что различить их очень трудно. Да и суть происходящего всегда далеко не так однозначна.";
    		link.l1 = "Как это?";
    		link.l1.go = "Step_13";
		break;

		case "Step_13":
        	dialog.text = "Это сложно объяснить точно в человеческих формулировках, но давай рассмотрим пример.\n"+
                          "Предположим, ты вылечил"+ GetSexPhrase("","а") +" человека от тяжелой болезни - это добрый поступок. Но твой добрый поступок является злым делом в отношении его несчастной падчерицы.\n"+
                          "Или, предположим, ты нанес"+ GetSexPhrase("","ла") +" человеку увечье - это злое деяние. Но это злое деяние будет благом для той же падчерицы, страдающей от своего отчима-тирана.";
    		link.l1 = "Хм, вот оно как...";
    		link.l1.go = "Step_14";
		break;
		
		case "Step_14":
        	dialog.text = "В итоге силы зла и добра в своем противостоянии совершают поступки, которые сложно квалифицировать однозначно.\n"+
                          "Таким образом, совершенно не обязательно, что я начну сейчас же сеять зло по отношению к тебе. Меня к этому ничего не обязывает, хоть я и демон.";
    		link.l1 = "Значит, я могу загадывать желания и ты их исполнишь?";
    		link.l1.go = "Step_15";
		break;
		
		case "Step_15":
        	dialog.text = "В принципе, да. Однако, есть одно очень большое НО.\n"+
                          "Заключается оно в том, что наши отношения со смертными регламентируются циркулярами. Пример я тебе уже приводил - обмен телами.\n"+
                          "Я могу действовать только в рамках этих правил. Так что давай обсудим твои желания.";
        	link.l1 = "С удовольствием.";
    		link.l1.go = "Wishes";
		break;

		case "Wishes":
            dialog.text = LinkRandPhrase("Внимательно тебя слушаю. Чего ты хочешь?", "Так чего ты хочешь?" , "Я слушаю тебя. Что ты хочешь?");
    		link.l1 = "Чтобы ты убивал моих врагов.";
    		link.l1.go = "ToKillEnemy";
    		link.l2 = "Денег.";
    		link.l2.go = "ToGiveMoney";
    		link.l4 = "Рому.";
    		link.l4.go = "ToGiveRum";
    		link.l5 = "Хороший корабль.";
    		link.l5.go = "ToShip";
    		link.l6 = "Бессмертие.";
    		link.l6.go = "ToImmortal";
    		link.l7 = "Стать генерал-губернатором Ямайки.";
    		link.l7.go = "ToGovernor";
    		link.l8 = "Стать "+ GetSexPhrase("самым сильным, ловким, умным, удачливым","самой сильной, ловкой, умной, удачливой") +"...";
    		link.l8.go = "ToAddSpecial";
    		link.l9 = "Все, более я ничего не хочу. Во всяком случае, в голову ничего не приходит.";
    		link.l9.go = "ToEnd";
		break;

		case "ToKillEnemy":
			dialog.text = NPCStringReactionRepeat("Убивать людей по твоему желанию? Совершенно неверный подход к пониманию сил Зла.",
                                           "Это твое желание мы уже обсуждали.",
                                           "Я же сказал, что это желание мы уже обсудили. Не надо выводить меня из себя, я ведь могу и потерять терпение.",
                                           "Так, похоже, что ты совершенно невменяемый человек. Итак, прощай смертн"+ GetSexPhrase("ый","ая") +".", "quest", 0, npchar, Dialog.CurrentNode);
            link.l1 = HeroStringReactionRepeat("Не очень понял"+ GetSexPhrase("","а") +"... А при чем здесь понимание?", "Да, точно, с этим все. Давай обсудим остальное.", "Извини, не хотел"+ GetSexPhrase("","а") +" тебя выводить из себя. Давай продолжим.", "Как прощай?!", npchar, Dialog.CurrentNode);
    		link.l1.go = DialogGoNodeRepeat("Step_16", "Wishes", "Wishes", "", npchar, Dialog.CurrentNode);
		break;

		case "Step_16":
        	dialog.text = "Да при том, " + GetFullName(pchar) + ", что силы зла, за редчайшим исключением, не убивают людей. Те страшилки, что вам с детства рассказывают няни и бабушки - не более чем сказки.";
    		link.l1 = "Но вы же охотитесь за нашими душами!";
    		link.l1.go = "Step_17";
		break;

    	case "Step_17":
        	dialog.text = "Верно, точно так же, как и силы добра охотятся за этими же самыми душами.\n"+
                          "Убийство человека совершенно не означает, что его душа попадет в Ад - это решает коллегия Страшного Суда. Задача темных сил состоит в том, чтобы обеспечить решение в нашу пользу.\n"+
                          "А это достигается не убийством человека, а потаканием его порокам. Его собственные поступки должны отдать нам его душу. Страсти в душе смертного должны из тлеющего уголька разгореться во всепожирающее пламя, а такой уголек есть у каждого в душе...";
    		link.l1 = "Хм, зайти в любую пещеру на архипелаге, так там полно вашего брата. Чуть зазеваешься - и снесут башку, особо не потакая моим порокам...";
    		link.l1.go = "Step_18";
		break;

		case "Step_18":
        	dialog.text = "Ах, это... К силам зла эти безумные толпы имеет весьма отдаленное отношение. Души некоторых умерших людей не попадают в канцелярию Старшного Суда, тому есть ряд причин.\n"+
                          "Есть у нас индейские демоны, выведены они в отдельный департамент, заправляет там ацтекский божок Миктлантехутль. Именно эта шайка заставляет душу, уже потерявшую после смерти сознание, управлять мертвым телом, и не обязательно своим.\n"+
                          "Дело это затратное и хлопотное - заставить мертвое тело двигаться, но, насколько мне известно, они нашли способ подвязать к этому делу элементалей стихий, производные от чистой природной энергии. Так что эти ходячие трупы по сути дела автономны.\n"+
						  "Зачем это нужно краснокожим - понятия не имею. Они у нас особняком держатся, их департамент отчеты предоставляет только высшему руководству. Странные они.\n"+
                          "Ко всему прочему, немотивированные убийства людей запрещены циркуляром №55115/13.";
    		link.l1 = "Значит, ты не сможешь никого убивать по моему желанию?";
    		link.l1.go = "Step_19";
		break;

		case "Step_19":
        	dialog.text = "Почему же, смогу. Хоть весь ближайший город пущу под нож, стоит тебе только пожелать. Только одно условие - за эту услугу я возьму твою бессмертную душу.\n"+
                          "А предварительно разорву и пожру твое тело - я демон, а Контрольно-ревизионное Управление Ада строго следит за выполнением демонами своих служебных обязанностей.\n"+
                          "Соглас"+ GetSexPhrase("ен","на") +"?";
    		link.l1 = "Нет, слишком малая цена за мою душу. Да я вообще ее продавать не собираюсь. Давай-ка лучше о других желаниях поговорим.";
    		link.l1.go = "Wishes";
		break;

		case "ToGiveMoney":
        	dialog.text = NPCStringReactionRepeat("Это можно.", "Это желание мы уже обсуждали.", "Повторяю, это желание мы уже обсудили, тебе не стоит доставать меня.", "Похоже, что ты самый скучный и занудный человек на этом свете. Прощай.", "quest", 0, npchar, Dialog.CurrentNode);
            link.l1 = HeroStringReactionRepeat("И что, потребуешь взамен мою душу?", "Верно, обсуждали. Лучше поговорим о других желаниях.", "Извини, не хотел"+ GetSexPhrase("","а") +" тебя выводить из себя. Давай продолжим.", "Как прощай?!", npchar, Dialog.CurrentNode);
            link.l1.go = DialogGoNodeRepeat("Step_20", "Wishes", "Wishes", "", npchar, Dialog.CurrentNode);
		break;

		case "Step_20":
        	dialog.text = "Вообще-то так и делается бесами: деньги, драгоценности, золото - а потом душа отправляется прямиком в ад. Но я демон, унижать себя мелкой аферой не намерен.\n"+
                          "К тому же, ты оказал"+ GetSexPhrase("","а") +" мне некоторую услугу, я не хочу причинять тебе вреда.";
    		link.l1 = "Уф-ф-ф, это радует...";
    		link.l1.go = "Step_21";
		break;

		case "Step_21":
        	dialog.text = "Деньгами я тебя обеспечу. Но дам тебе их не я.\n"+
                          "В городе Чарльстаун подойдешь к ростовщику, его зовут " + GetFullName(characterFromId("Charles_usurer")) + ". Скажешь ему, что он должен тебе три миллиона и немедленно получишь все сумму целиком.";
    		link.l1 = "Хм, он что, уже продал вам душу?";
    		link.l1.go = "Step_22";
    		pchar.questTemp.Azzy.GiveMoney = 1;
		break;

		case "Step_22":
        	dialog.text = "Ха-ха-ха! Каждый человек, ссужающий деньги под процент, уже продал нам душу.\n"+
                          "Некоторые просто об этом не догадываются. До поры...\n"+
                          "Ну ладно, не будем отвлекаться. Ты довол"+ GetSexPhrase("ен","ьна") +"? Или твоя душа требует еще исполнения желаний? Ха-ха!";
    		link.l1 = "Уф-ф-ф, хотелось бы еще посмотреть на прейскурант.";
    		link.l1.go = "Wishes";
		break;

		case "ToGovernor":
        	dialog.text = NPCStringReactionRepeat("Очень хорошо. Отныне ты - губернатор Ямайки. Никаких проблем.",
                                                  "Губернатором ты уже становил"+ GetSexPhrase("ся","ась") +".",
                                                  "Я уже делал тебя губернатором Ямайки. Снова делать?",
                                                  "Похоже, что ты самый глупый человек на Земле. Прощай.", "quest", 0, npchar, Dialog.CurrentNode);
    		link.l1 = HeroStringReactionRepeat("Значит, я могу идти в свою резиденцию в Порт Рояле? И английский флот в Карибском море будет мне подчинен? И я смогу общаться с королем?", "Да, точно. Становил"+ GetSexPhrase("ся","ась") +" губернатором Ямайки...", "Даже не знаю, стоит ли?...", "Как прощай?!", npchar, Dialog.CurrentNode);
    		link.l1.go = DialogGoNodeRepeat("Step_25", "Wishes", "Wishes", "", npchar, Dialog.CurrentNode);
		break;
		
		case "Step_25":
        	dialog.text = "Ну, как бы тебе сказать... С этим сложней.";
    		link.l1 = "Какие сложности? Ты же меня сделал губернатором Ямайки!";
    		link.l1.go = "Step_26";
		break;

		case "Step_26":
        	dialog.text = "Это верно. Однако сделал губернатором только тебя, на окружающий мир я никак не воздействовал.";
    		link.l1 = "То есть, окружающие не будут воспринимать меня как губернатора? А зачем мне тогда все это?";
    		link.l1.go = "Step_27";
		break;

		case "Step_27":
        	dialog.text = "Откуда мне знать, зачем тебе это? Ты захотел"+ GetSexPhrase("","а") +" быть губернатором - я тебя им сделал.\n"+
                          "Однако для того, чтобы и окружающий мир тебя воспринимал как губернатора, я должен буду изменить ход событий в прошлом.\n"+
                          "Мне придется смоделировать целую цепь событий, которая привела тебя к креслу губернатора. Соответственно, события окружающего мира и людей вокруг тоже будут изменены. К чему это приведет в итоге - не смогу точно сказать даже я.\n"+
                          "То есть, вполне может случиться, что в результате такого вмешательства мир изменится до неузнаваемости. А существующую реальность мне нужно будет утилизировать согласно ведомственному циркуляру №315/188.\n"+
                          "Ты к таком обороту готов"+ GetSexPhrase("","а") +"?";
    		link.l1 = "Нет, не готов"+ GetSexPhrase("","а") +"! Что-то все у вас сложно...";
    		link.l1.go = "Step_28";
		break;

		case "Step_28":
        	dialog.text = "Так что, ты и просто губернатором быть не хочешь?";
    		link.l1 = "Нет, не хочу. Давай посмотрим, что ты еще можешь мне предложить.";
    		link.l1.go = "Wishes";
		break;
		
		case "ToImmortal":
        	dialog.text = dialog.text = NPCStringReactionRepeat("Желаешь бессмертия? Это можно. Только давай уточним, что ты точно имеешь в виду под словом бессмертие. Ты хочешь, чтобы твоя душа не покидала тела по причинам различного порядка, вызывающим обычно смерть? Это так?",
                                    "О бессмертии мы уже говорили.",
                                    "Повторяю, вопрос бессмертия мы уже обсудили, тебе не стоит раздражать меня.",
                                    "Похоже, что ты самый глупый человек в подлунном мире. Прощай.", "quest", 0, npchar, Dialog.CurrentNode);
    		link.l1 = HeroStringReactionRepeat("Ну, по сути да...", "Да, точно, с бессмертием вопрос закрыт.", "Обсудили и все решили, ты абсолютно прав!", "Как прощай?!", npchar, Dialog.CurrentNode);
    		link.l1.go = DialogGoNodeRepeat("Step_29", "Wishes", "Wishes", "", npchar, Dialog.CurrentNode);
		break;

		case "Step_29":
        	dialog.text = "Это можно организовать. Только ты долж"+ GetSexPhrase("ен","на") +" понимать, что раны, нанесенные тебе в боях, приведут к разложению твоего тела.\n"+
                          "Вскоре ты станешь одним из тех существ, которыми наводнены здешние катакомбы - живым трупом, похожим на моего друга Лейфа. Мы об этом говорим?";
    		link.l1 = "Нет, не об этом. Если быть точным, то я хочу, чтобы вражеские клинки и пули не причиняли вреда моему телу.";
    		link.l1.go = "Step_30";
		break;

		case "Step_30":
        	dialog.text = "Теперь ясно. Только это не бессмертие, это неуязвимость. Можно организовать.\n"+
                          "Только здесь есть проблема - большие трудозатраты в плане реализации. Одно дело - привязать душу к телу навечно, это пустяк. А другое дело - хранить тело в неприкосновенности под градом пуль, это требует серьезных затрат энергии.";
    		link.l1 = "Что?! Аззи, ты же демон, сверхъестественное существо. Ты можешь все, а рассказываешь мне о каких-то трудозатратах...";
    		link.l1.go = "Step_31";
		break;

		case "Step_31":
        	dialog.text = "А чего ты хотел"+ GetSexPhrase("","а") +"? Мы все живем по законам мироздания, просто вы законов этих не знаете.\n"+
                          "В общем, так: хочешь неуязвимости - я скажу, что ты долж"+ GetSexPhrase("ен","на") +" сделать, чтобы все это работало.";
    		link.l1 = "Хочу. Говори, что я долж"+ GetSexPhrase("ен","на") +" делать.";
    		link.l1.go = "Step_32";
		break;
		
		case "Step_32":
        	dialog.text = "Итак, ты заключаешь контракт с Департаментом Ада по учету людей. На основании этого контракта, ты долж"+ GetSexPhrase("ен","на") +" будешь обеспечивать данный адский Департамент необходимым количеством жизненной энергии, которую китайцы зовут ци.\n"+
                          "Также подойдет и чистая природная энергия, которой питается вся эта нечисть в пещерах и катакомбах.";
    		link.l1 = "Как это обеспечивать? Что конкретно мне делать, чтобы достать эту энергию?";
    		link.l1.go = "Step_33";
		break;

		case "Step_33":
        	dialog.text = "Ты долж"+ GetSexPhrase("ен","на") +" будешь делать то, чем и так занимаешься ежедневно - отправлять на тот свет людей и нечисть.\n"+
                          "А адский Департамент автоматически зачисляет на твой баланс высвобожденную энергию, которая и идет в обеспечение твоей неуязвимости.";
    		link.l1 = "А без этого никак нельзя? Я действительно ежедневно отправляю на тот свет немало народу, однако делаю это по своей воле...";
    		link.l1.go = "Step_34";
		break;

		case "Step_34":
        	dialog.text = "Слушай, "+ GetSexPhrase("мон шер","дорогая") +", я тебе оказываю огромную услугу. Ты что думаешь, такие контракты с Департаментом Ада по учету людей на дороге валяются?\n"+
                          "Такие контракты - дело редкое и эксклюзивное. Иначе нельзя, чудес на свете не бывает.";
    		link.l1 = "А сколько я долж"+ GetSexPhrase("ен","на") +" буду убивать людей или нечисти для нормального функционирования системы моей неуязвимости?";
    		link.l1.go = "Step_35";
		break;

		case "Step_35":
        	dialog.text = "Это Департамент как генеральный подрядчик определяет. Но там без особых проблем - несколько единиц в день и все.\n"+
                          "Я же говорю, ты и так это делаешь ежедневно. Проблем не вижу...\n"+
                          "Ну так что, ты соглас"+ GetSexPhrase("ен","на") +"?";
    		link.l1 = "Да, соглас"+ GetSexPhrase("ен","на") +". Мне кровью расписаться?";
    		link.l1.go = "Step_36";
    		link.l2 = "Нет, не соглас"+ GetSexPhrase("ен","на") +". Пусть все остается, как есть. Давай лучше посмотрим, что у тебя еще есть в плане исполнения моих желаний.";
    		link.l2.go = "Wishes";
		break;

		case "Step_36":
        	dialog.text = "Кровью?! Хех, где ты начитал"+ GetSexPhrase("ся","ась") +" этих дешевых мистических романов?\n"+
                          "Просто скажи: 'Я, " + GetFullName(pchar) + ", находясь в здравом уме, заключаю контракт с демоном Аззи для обеспечения неуязвимости моего тела.'";
    		link.l1 = "Я, " + GetFullName(pchar) + ", находясь в здравом уме, заключаю контракт с демоном Аззи для обеспечения неуязвимости моего тела.";
    		link.l1.go = "Step_37";
		break;

		case "Step_37":
        	dialog.text = "Ну вот и все. Текст контракта занесен тебе в судовой журнал, ознакомься на досуге.\n"+
                          "Поздравляю тебя. Ты теперь совершенно неуязвим"+ GetSexPhrase("","а") +".";
    		link.l1 = "Это здорово! Слушай, я хочу посмотреть, что ты еще можешь мне предложить в плане исполнения желаний.";
    		link.l1.go = "Wishes";
    		LAi_SetImmortal(pchar, true);
            SetQuestHeader("ContractWithHell");
            AddQuestRecord("ContractWithHell", "1");
			AddQuestUserData("ContractWithHell", "Conrtragent", GetFullName(pchar));
            pchar.questTemp.Azzy.Immortal = 1;
            SaveCurrentQuestDateParam("questTemp.Azzy");
            SaveCurrentQuestDateParam("questTemp.Azzy.Immortal");
            pchar.questTemp.Azzy.Immortal.AllQuota = 0;
            pchar.questTemp.Azzy.Immortal.DayQuota = 3; //ежедневный норматив
            pchar.questTemp.Azzy.Immortal.CurBalance = 0;
            pchar.questTemp.Azzy.Immortal.CurKilled = 0;
            pchar.questTemp.Azzy.Immortal.Penalty = 0;
            pchar.questTemp.Azzy.Immortal.EarlyKilled = Statistic_AddValue(PChar, "Solder_s", 0) +
                                                 Statistic_AddValue(PChar, "Solder_g", 0) +
                                                 Statistic_AddValue(PChar, "Warrior_s", 0) +
                                    	         Statistic_AddValue(PChar, "Warrior_g", 0) +
                                    	         Statistic_AddValue(PChar, "Citizen_s", 0) +
                                    	         Statistic_AddValue(PChar, "Citizen_g", 0) +
                                    	         Statistic_AddValue(PChar, "Monster_s", 0) +
                                    	         Statistic_AddValue(PChar, "Monster_g", 0);
            AddQuestRecord("Azzy_HellSign", "1");
			AddQuestUserData("Azzy_HellSign", "sName", GetMainCharacterNameGen());
			AddQuestUserData("Azzy_HellSign", "DayQuota", pchar.questTemp.Azzy.Immortal.DayQuota);
			AddQuestUserData("Azzy_HellSign", "AllQuota", pchar.questTemp.Azzy.Immortal.AllQuota);
			AddQuestUserData("Azzy_HellSign", "CurKilled", pchar.questTemp.Azzy.Immortal.CurKilled);
			AddQuestUserData("Azzy_HellSign", "CurBalance", pchar.questTemp.Azzy.Immortal.CurBalance);
		break;

		case "ToGiveRum":
        	dialog.text = NPCStringReactionRepeat("У тебя денег предостаточно. Ты что, не можешь себя ромом обеспечить?",
                                    "Опять о роме? Вопрос же решен...",
                                    "Не зли меня, я не хочу повторяться.",
                                    "Похоже, что ты самый глупый человек в подлунном мире. Прощай.", "quest", 0, npchar, Dialog.CurrentNode);
    		link.l1 = HeroStringReactionRepeat("Могу и обеспечиваю. Но знаешь, сегодня деньги есть, завтра их может и не быть. А рома хочется всегда!", "Верно, все решили!", "Извини...", "Как прощай?!", npchar, Dialog.CurrentNode);
    		link.l1.go = DialogGoNodeRepeat("Step_38", "Wishes", "Wishes", "", npchar, Dialog.CurrentNode);
		break;

		case "Step_38":
        	dialog.text = "Ну что ж, это можно организовать. Давай договоримся так: если тебе будет нужен ром, то ты сможешь получать его бесплатно в магазине Порт-о-Принса у продавца по имени " + GetFullName(characterFromId("PortPax_trader")) + ".";
    		link.l1 = "Хорошо, это было бы здорово! Дармовой ром - мечта пирата! А я за это тебе ничего не буду долж"+ GetSexPhrase("ен","на") +"?";
    		link.l1.go = "Step_39";
    		pchar.questTemp.Azzy.GiveRum = 1;
		break;

		case "Step_39":
        	dialog.text = "Ничего. Это я делаю за счет собственных ресурсов, не привлекаю никого дополнительно.";
    		link.l1 = "Это хорошо. Ну что ж, давай посмотрим, что у тебя еще интересного в плане исполнения желаний?";
    		link.l1.go = "Wishes";
		break;

		case "ToAddSpecial":
        	dialog.text = NPCStringReactionRepeat("Это можно устроить. Так как"+ GetSexPhrase("им","ой") +" ты хочешь стать?",
                                    "Я отправил тебя к одной особе, не вижу смысла повторяться.",
                                    "Не зли меня, я не хочу повторяться.",
                                    "Похоже, что ты самый глупый человек в подлунном мире. Прощай.", "quest", 0, npchar, Dialog.CurrentNode);
    		link.l1 = HeroStringReactionRepeat("Ну, не знаю... Силы бы не помешало, удачливости...", "Да, верно, дорогу к ней я найду...", "Извини...", "Как прощай?!", npchar, Dialog.CurrentNode);
    		link.l1.go = DialogGoNodeRepeat("Step_40", "Wishes", "Wishes", "", npchar, Dialog.CurrentNode);
		break;

		case "Step_40":
        	dialog.text = "Ясно. В общем, на Тортуге есть бордель, содержит его некая Маргарита. Эта женщина - ведьма, она может сделать то, что тебе нужно. За то время, что ты к ней доберешься, я с ней договорюсь.";
    		link.l1 = "Хорошо, зайду к ней, спасибо тебе. А что еще можно у тебя пожелать?";
    		link.l1.go = "Wishes";
    		pchar.questTemp.Azzy.AddSpecial = 1;
		break;

		case "ToShip":
        	dialog.text = NPCStringReactionRepeat("Что значит хороший?",
                                    "Мы уже говорили про корабли...",
                                    "Я понимаю твою мечту о Летучем Голландце, но мы уже обсудили все.",
                                    "Похоже, что ты самый глупый человек в подлунном мире. Прощай.", "quest", 0, npchar, Dialog.CurrentNode);
    		link.l1 = HeroStringReactionRepeat("Чтобы он по скорости превосходил любой из существующих, чтобы паруса не рвались от ветра и книппелей, чтобы ядра отлетали от бортов, не причиняя вреда...", "Да, корабли - моя любимая тема...", "Я о Черной Жемчужине говорил"+ GetSexPhrase("","а") +", но тем не менее все верно.", "Как прощай?! А как же корабли?", npchar, Dialog.CurrentNode);
    		link.l1.go = DialogGoNodeRepeat("Step_41", "Wishes", "Wishes", "", npchar, Dialog.CurrentNode);
		break;

		case "Step_41":
        	dialog.text = "Этого я делать не буду - затратно очень.";
    		link.l1 = "А 'Летучий Голландец'?";
    		link.l1.go = "Step_42";
		break;

		case "Step_42":
        	dialog.text = "'Летучий Голландец' находится под серьезным проклятием. Куча индейских демонов только тем и занимается, что отслеживает состояние данного проклятия и поддерживает его функциональность.\n"+
                          "Или ты предложишь мне к тебе в команду записаться, чтобы обеспечивать сохранность твоей посудины и поддерживать ее хороший ход?!";
    		link.l1 = "Нет, конечно, даже и в мыслях не было, уважаемый Аззи...";
    		link.l1.go = "Step_43";
		break;

		case "Step_43":
        	dialog.text = "И это правильно, так как небезопасно для тебя.\n"+
                          "Хотя подожди, точно я не помню, но защита именно корпуса корабля проводится в рамках одного из контрактов со смертными.\n"+
                          "А вообще, советую тебе посетить верфь на Бермудах, заправляет там Мастер, он местные парусники доводит до ума.";
    		link.l1 = "Уважаемый Аззи, спасибо за совет, я обязательно им воспользуюсь. А сейчас могу я услышать еще что-нибудь об исполнении желаний?";
    		link.l1.go = "Wishes";
            if (CheckAttribute(pchar, "questTemp.Azzy.Immortal"))
		    {
            	dialog.text = "Подожди, мы же заключили контракт на твою неуязвимость. Так вот, в данном контракте прописывается и сохранность корпуса твоего корабля, чтобы ты не утонул"+ GetSexPhrase("","а") +" ненароком посреди океана. А то договаривайся потом с русалками, чтобы вытащили тебя из пучины...";
        		link.l1 = "Аззи, это же просто здорово! Я могу услышать еще что-нибудь об исполнении желаний?";
		    }
		break;

		case "ToEnd":
        	dialog.text = "Ты меня изрядно утомил"+ GetSexPhrase("","а") +", зато я проверил свое терпение. И пусть теперь не говорят ангелы, что демоны - дикие и необузданные существа.\n"+
                          "Мне было приятно с тобой разговаривать. Если ты когда-нибудь осмелишься вызвать меня, то обещаю, что выслушаю тебя как минимум, а не пожру твое тело немедленно. Ха-ха-ха.\n"+
                          "Прощай, "+ GetSexPhrase("капер","" + pchar.name + "") +".";
    		link.l1 = "Прощай, Аззи. Спасибо тебе.";
    		link.l1.go = "Back_Exit";
		break;

 		case "Back_Exit":
            LAi_LocationFightDisable(&Locations[FindLocation("Shore28")], false);
 		    ChangeCharacterAddress(characterFromID("Azzy"), "None", "");
 		    DoReloadCharacterToLocation(pchar.questTemp.Ascold.ShipyarderColony + "_Shipyard", "reload", "reload2");
 		    LAi_SetPlayerType(PChar);
 		    NextDiag.TempNode = "Second time";
            NextDiag.CurrentNode = NextDiag.TempNode;
			DialogExit();
		break;

 		case "Azzy_Exit":
 		    ChangeCharacterAddress(characterFromID("Azzy"), "None", "");
 		    LAi_SetPlayerType(PChar);
 		    NextDiag.TempNode = "Death";
            NextDiag.CurrentNode = NextDiag.TempNode;
			DialogExit();
		break;

 		case "Exit":
            NextDiag.CurrentNode = NextDiag.TempNode;
			DialogExit();
		break;

		case "Second time":
        	dialog.text = "Та-а-ак, опять я на вызовах... " + GetFullName(pchar) + ", ты же знаешь - я этого терпеть не могу. Сейчас тебе придется очень постараться, дабы разъяснить причину.";
    		link.l1 = "Аззи, я хочу разорвать контракт на неуязвимость.";
    		link.l1.go = "Step_44";
		break;

		case "Step_44":
        	dialog.text = "А с чего это вдруг? Такими контрактами не разбрасываются. Неуязвимость, знаешь ли...";
    		link.l1 = "Аззи!!! Твоя эта контора в аду постоянно повышает ставки в игре! Я жизнью рискую!!!";
    		link.l1.go = "Step_45";
		break;

		case "Step_45":
        	dialog.text = "И душой своей бессмертной. А чего ты хотел"+ GetSexPhrase("","а") +"? Шашни с силами зла смертного приводят точно в Aд.";
    		link.l1 = "Аззи! Я хочу расторгнуть контракт. В тексте есть пункт, предусматривающий данный вопрос. Но мы должны были встретиться, поэтому я тебя и вызвал"+ GetSexPhrase("","а") +".";
    		link.l1.go = "Step_46";
		break;

		case "Step_46":
        	dialog.text = "Хм, хорошо. Скажи: 'При согласии Аззи я расторгаю контракт на мою неуязвимость'. И всего делов-то.";
    		link.l1 = "При согласии Аззи я расторгаю контракт на мою неуязвимость!!!";
    		link.l1.go = "Step_47";
		break;

		case "Step_47":
        	dialog.text = "Хм, с каким чувством сказано! Ну ладно, все в порядке - ты теперь опять уязвим"+ GetSexPhrase("","а") +". Контракт расторгнут.";
    		link.l1 = "Спасибо, Аззи. Ты мне спас больше, чем жизнь...";
    		link.l1.go = "Step_48";
			pchar.questTemp.Azzy = "over";
    		LAi_SetImmortal(pchar, false);
    		DeleteAttribute(pchar, "questTemp.Azzy.Immortal");
    		DeleteQuestHeader("ContractWithHell");
    		DeleteQuestHeader("Azzy_HellSign");
		break;

		case "Step_48":
        	dialog.text = "Это верно. Ну что ж, давай прощаться, смертн"+ GetSexPhrase("ый","ая") +". Теперь уже навечно, поскольку еще один вызов меня будет стоить тебе жизни.\n"+
                          "Попытайся замолить свои грехи, может, и получится. Прощай...";
    		link.l1 = "Прощай, Аззи. Я постараюсь.";
    		link.l1.go = "Azzy_Exit";
			npchar.lifeDay = 0;
		break;
		//помощь ГГ, если вляпался с долгом у ростовщика ГПК
		case "ClimeUsurer":
			dialog.text = "Хе-хе... Что, "+ GetSexPhrase("приятель, вляпался","подруга, вляпалась") +"?";
			link.l1 = "Аззи, черт возьми, как я рад"+ GetSexPhrase("","а") +" тебя видеть!!!";
			link.l1.go = "ClimeUsurer_1";
		break;
		case "ClimeUsurer_1":
			dialog.text = "Не чертыхайся, не люблю я этого\nЧто делать-то думаешь?";
			link.l1 = "Думал"+ GetSexPhrase("","а") +", что все, конец мне. Теперь, вот, уже так не думаю. Аззи, как я рад"+ GetSexPhrase("","а") +" тебя видеть, дружище!..";
			link.l1.go = "ClimeUsurer_2";
		break;
		case "ClimeUsurer_2":
			dialog.text = "Да и я, признаться, тоже. Ты меня забавляешь, смертн"+ GetSexPhrase("ый","ая") +". Все что-то тебе надо, все куда-то не в свое дело лезешь\nСейчас умудрил"+ GetSexPhrase("ся","ась") +" с индейскими демонами связаться. Угораздило же...";
			link.l1 = "Аззи, я и подумать не мог"+ GetSexPhrase("","ла") +", что дойдет до такого! Кстати, а где это я, ты не в курсе?";
			link.l1.go = "ClimeUsurer_3";
		break;
		case "ClimeUsurer_3":
			dialog.text = "Ты в Теночтитлане, заброшенной столице ацтеков. Демона, что тебя забрал, зовут Миктлантекутли. Он тут из себя строит царя мертвых ацтеков.";
			link.l1 = "Вот это да... Аззи, выручи, дружище!";
			link.l1.go = "ClimeUsurer_4";
		break;
		case "ClimeUsurer_4":
			dialog.text = "Даже не знаю... Он тебя ведь по делу закрыл. На кой ляд ты деньги брал"+ GetSexPhrase("","а") +" у его прихвостня?";
			link.l1 = "Аззи, если бы я знал"+ GetSexPhrase("","а") +", то ни за какие коврижки на это не пош"+ GetSexPhrase("ел","ла") +"! Клянусь тебе...";
			link.l1.go = "ClimeUsurer_5";
		break;
		case "ClimeUsurer_5":
			dialog.text = "Да ладно, верю\nВот что, я тебя отсюда уберу, но ты смотри аккуратней в дальнейшем. Понял меня?";
			link.l1 = "Понял"+ GetSexPhrase("","а") +", не дура"+ GetSexPhrase("к","") +".";
			link.l1.go = "ClimeUsurer_6";
		break;
		case "ClimeUsurer_6":
			dialog.text = "Ладно, прощай, смертн"+ GetSexPhrase("ый","ая") +".";
			link.l1 = "Спасибо тебе, Аззи, от всего сердца...";
			link.l1.go = "exit";
			AddDialogExitQuestFunction("ClimeUsurer_haveMoney");
		break;

// ======================== блок нод angry ===============>>>>>>>>>>>>>>>
		//==> попытки дать денег
		case "AngryQuest":
            Dialog.text = GetFullName(pchar)+ ", в этом мире есть гораздо более интересные и приятные вещи, нежели общение с таким занудой.";
			Link.l1 = "Послушай...";
		    Link.l1.go = "AngStep_1";
    	break;

		case "AngStep_1":
            Dialog.text = "И слушать не буду! Прощай, смертн"+ GetSexPhrase("ый","ая") +"...";
			Link.l1 = "...";
		    Link.l1.go = "Back_Exit";
            DeleteAttribute(npchar, "angry.ok");
            Dialog.CurrentNode = "Back_Exit";
    	break;

		case "AngryExitAgain":
 		    ChangeCharacterAddress(characterFromID("Azzy"), "None", "");
 		    LAi_SetPlayerType(PChar);
            NextDiag.CurrentNode = NextDiag.TempNode;
            DialogExit();
            DeleteAttribute(npchar, "angry.ok");
		break;

// <<<<<<<<<<<<============= блок нод angry =============================
	}
}


