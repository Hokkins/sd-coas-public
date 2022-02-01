// диалог по городам
void ProcessCommonDialogEvent(ref NPChar, aref Link, aref NextDiag)
{

	switch (Dialog.CurrentNode)
	{
		case "quests":
			dialog.text = NPCStringReactionRepeat("Спрашивай, чего ты хочешь?",
                          "Мы только что поднимали это тему. Вы, вероятно, запамятовали...", "Сегодня вы уже третий раз говорите о каком-то вопросе...",
                          "Послушай, это магазин, здесь люди покупают что-то. Не отвлекай меня!", "block", 1, npchar, Dialog.CurrentNode);
			link.l1 = HeroStringReactionRepeat("Знаешь, " + NPChar.name + ", как-нибудь в следующий раз.", "Точно, "+ GetSexPhrase("забыл","забыла") +" что-то...",
                      "Да уж, действительно в третий раз...", "Гм, не буду...", npchar, Dialog.CurrentNode);
			link.l1.go = "exit";
			if (pchar.questTemp.BlueBird == "toPuertoPrincipe")
			{
				link.l1 = "Джон, я к тебе по делу касательно Паскаля Вуазье.";
				link.l1.go = "BlueBird_1";
			}
		break;
		case "BlueBird_1":
			if (isBadReputation(pchar, 5)) 
			{
				dialog.text = NPCStringReactionRepeat("Я не буду разговаривать о Паскале с человеком, имеющим репутацию, подобную вашей. Я готов заниматься с вами торговлей, не более.", 
					"Я уже все вам сказал.", 
					"Мы уже говорили на эту тему.",
					"Мне нечего добавить к сказанному.", "block", 1, npchar, Dialog.CurrentNode);
				link.l1 = HeroStringReactionRepeat("Но мне очень нужен разговор с тобой, постарайся это понять...", 
					"Хм...",
					"Да, точно...", 
					"Понятно...", npchar, Dialog.CurrentNode);
				link.l1.go = DialogGoNodeRepeat("BlueBird_close", "", "", "", npchar, Dialog.CurrentNode);
			}
			else
			{
				dialog.text = "Хм, даже не знаю, что сказать... И что это за дело?";
				link.l1 = "Ну... Вот, дьявол, теперь я не знаю, что сказать.";
				link.l1.go = "BlueBird_2";
			}
		break;

		case "BlueBird_close":
			dialog.text = "Подумайте лучше о своей репутации... Мне больше нечего вам сказать.";
			link.l1 = "Хех!..";
			link.l1.go = "exit";
		break;

		case "BlueBird_2":
			dialog.text = "Начни с главного.";
			link.l1 = "Пожалуй, так и поступлю. У меня есть подозрение, что Паскаль Вуазье является не просто торговцем. Мне сказали, что вы, вроде как, враги. Поэтому я здесь, хочу узнать как можно больше об этом человеке.";
			link.l1.go = "BlueBird_3";
		break;
		case "BlueBird_3":
			dialog.text = "Ха! Неужели хоть кто-то в Карибском море прозрел? "+ GetSexPhrase("Друг мой","Девушка") +", Паскаль Вуазье действительно не просто торговец. Он форменный негодяй, но умеет делать дела по-тихому, поэтому ему все и сходит с рук...";
			link.l1 = "Что все? Что ему сходит с рук?";
			link.l1.go = "BlueBird_4";
		break;
		case "BlueBird_4":
			dialog.text = "Начнем с того, как этот мерзавец забрал у меня магазин. Он лишил меня поступлений товаров, даже местные пираты ничего мне не продавали, он скупал у них все!";
			link.l1 = "Ого, а хватка у него как у волка!";
			link.l1.go = "BlueBird_5";
		break;
		case "BlueBird_5":
			dialog.text = "Как у шакала, вот так сказать будет правильно! И ты представь себе - все торговое сообщество Карибского моря считает его порядочным человеком! А вот я думаю, что все беды торговцев - его рук дело.";
			link.l1 = "Ты думаешь?";
			link.l1.go = "BlueBird_6";
		break;
		case "BlueBird_6":
			dialog.text = "Уверен. Только никто меня не слушает, все думают, что это говорит обида на него за потерянное дело на Бермудах. Оно, конечно, не без этого, но не до такой же степени!\nА потом я вообще перестал что-то говорить - намекнули добрые люди, чтобы я поутих...";
			link.l1 = "М-да... Ты знаешь, я сейчас занимаюсь поисками шебеки 'Синяя Птица'. Именно этот корабль грабит личные суда торговцев.";
			link.l1.go = "BlueBird_7";
		break;
		case "BlueBird_7":
			dialog.text = "Думаю, что эта шебека действует как минимум по наводке мерзавца Паскаля. И очень даже может быть, что это и вовсе его корабль\nТы рассуди, каков хитрец - грабит торговцев, а потом ссужает им их же деньги!";
			link.l1 = "М-да, слов нет... Послушай, так как же мне отловить эту шебеку?";
			link.l1.go = "BlueBird_8";
		break;
		case "BlueBird_8":
			dialog.text = "Не знаю... Но вот что посоветую. Подумай, как он доставляет товар к себе в магазин. В порт его шебека вряд ли причаливает.";
			link.l1 = "Не причаливает точно, это я "+ GetSexPhrase("узнавал","узнавала") +".";
			link.l1.go = "BlueBird_9";
		break;
		case "BlueBird_9":
			dialog.text = "Ну вот, значит ход моих рассуждений верен... Ты знаешь, на Бермудах есть подземный ход, ведет из верфи прямо в бухту. В общем, ищи, "+ GetSexPhrase("приятель","подруга") +", да прибудет с тобой сила!";
			link.l1 = "Спасибо тебе, ты очень мне помог!";
			link.l1.go = "exit";
			pchar.questTemp.BlueBird = "toSeekBermudes";
			AddQuestRecord("Xebeca_BlueBird", "4");
		break;
	}
	UnloadSegment(NPChar.FileDialog2);
}

