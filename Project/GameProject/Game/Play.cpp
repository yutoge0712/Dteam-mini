#include "Play.h"
#include "Notes.h"
#include "SoundBar.h"
#include "SelectScene/SelectScene.h" 
#include <Gllibrary.h>
#include <iostream>
Play::Play(int ChoiceSound) : Base(eType_Play) {
	glClearColor(0, 0, 0, 0);
	CountDownToStart = 190;
	CountUpToEnd = 0;
	SoundNum = ChoiceSound;
	ImageSet();
	switch (ChoiceSound) {
	case eNum_LeanOn:
		video = new CVideo("Movie/LeanOn60.mp4");
	}
}
void Play::Draw() {
	if (CountDownToStart <= 0) {
		video->Draw();
	}
	Lane.Draw();
	NotesBar.Draw();
}
void Play::Update() {
	CountDownToStart--;
	CountUpToEnd++;
	if (CountDownToStart == 0) {
		switch (SoundNum) {
		case eNum_LeanOn:
			LeanOn();
		}
	}
	if (CountUpToEnd >= 7080) {
		Base::KillAll();
		Base::Add(new SelectScene());
	}
}
void Play::ImageSet() {
	Lane = COPY_RESOURCE("Lane", CImage);
	NotesBar = COPY_RESOURCE("NotesBar", CImage);
}
void Play::LeanOn() {
	video->Play();
	OneNotes = 18.125;
	Base::Add(new SoundBar(0));
	NotesSet();
}
void Play::NotesPreSet(int SetNum) {
	switch (SetNum) {
	case 0:
		Base::Add(new Notes(0, OneNotes * 0 + NotesCount, 5));
		Base::Add(new Notes(1, OneNotes * 2 + NotesCount, 8));
		Base::Add(new Notes(2, OneNotes * 4 + NotesCount, 10));
	}
	switch (SoundNum) {
	case eNum_LeanOn:
		NotesCount += 145.3;
	}
}
void Play::NotesSet() {
	switch (SoundNum) {
	case eNum_LeanOn:
		NotesCount = -117.75;
		NotesPreSet(0);
		NotesPreSet(0);
		NotesPreSet(0);
		NotesPreSet(0);
		NotesPreSet(0);
		NotesPreSet(0);
		NotesPreSet(0);
		NotesPreSet(0);
		NotesPreSet(0);
		NotesPreSet(0);
		NotesPreSet(0);
		NotesPreSet(0);
		NotesPreSet(0);
		NotesPreSet(0);
		NotesPreSet(0);
		NotesPreSet(0);
		NotesPreSet(0);
		NotesPreSet(0);
		NotesPreSet(0);
		NotesPreSet(0);
		NotesPreSet(0);
		NotesPreSet(0);
		NotesPreSet(0);
		NotesPreSet(0);
		NotesPreSet(0);
		NotesPreSet(0);
		NotesPreSet(0);
		NotesPreSet(0);
		NotesPreSet(0);
		NotesPreSet(0);
		NotesPreSet(0);
		NotesPreSet(0);
		NotesPreSet(0);
		NotesPreSet(0);
		NotesPreSet(0);
		NotesPreSet(0);
		NotesPreSet(0);
		NotesPreSet(0);
		NotesPreSet(0);
		NotesPreSet(0);
		NotesPreSet(0);
		NotesPreSet(0);
		NotesPreSet(0);
		NotesPreSet(0);
		NotesPreSet(0);
	}
}