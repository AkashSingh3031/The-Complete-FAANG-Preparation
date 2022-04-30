const musicPlayer = document.querySelector('.music_player'),
    musicImg = musicPlayer.querySelector('.imgBox img'),
    musicName = musicPlayer.querySelector('.songDetails .name'),
    musicArtist = musicPlayer.querySelector('.songDetails .artist'),
    mainAudio = musicPlayer.querySelector('#mainAudio'),
    playPauseBtn = musicPlayer.querySelector('.play-pause'),
    prevBtn = musicPlayer.querySelector('#prev'),
    nextBtn = musicPlayer.querySelector('#next'),
    progressArea = musicPlayer.querySelector('.progressBox'),
    progressBar = musicPlayer.querySelector('.progress-bar'),
    equalizer = musicPlayer.querySelector('#equalizer'),

    musicList = document.querySelector('.music_list'),
    volMuteBtn = musicPlayer.querySelector('#vol');

let musicIndex = Math.floor((Math.random() * songs.length) + 1);

window.addEventListener('load', () => {
    loadMusic(musicIndex);
    playingNow();
});

const loadMusic = (indexNum) => {
    musicName.textContent = songs[indexNum - 1].name;
    musicArtist.textContent = songs[indexNum - 1].artist;
    musicImg.src = `./assets/images/${songs[indexNum - 1].img}.jpg`
    mainAudio.src = `./assets/songs/${songs[indexNum - 1].src}.mp3`
    // mainAudio.src = `https://www.mboxdrive.com/${songs[indexNum - 1].src}.mp3`
}

// play music function
const playMusic = () => {
    musicPlayer.classList.add('paused');
    playPauseBtn.querySelector('i').textContent = "pause";
    musicImg.classList.add('anim');
    mainAudio.play();
    equalizer.load("https://assets7.lottiefiles.com/packages/lf20_btTua7.json");
}

// pause music function
const pauseMusic = () => {
    musicPlayer.classList.remove('paused');
    playPauseBtn.querySelector('i').textContent = "play_arrow";
    musicImg.classList.remove('anim');
    mainAudio.pause();
    equalizer.load("");
}

// next music function
const nextMusic = () => {
    musicIndex++;
    musicIndex > songs.length ? musicIndex = 1 : musicIndex = musicIndex;
    loadMusic(musicIndex);
    playMusic();
    playingNow();
}

// prev music function
const prevMusic = () => {
    musicIndex--;
    musicIndex < 1 ? musicIndex = songs.length : musicIndex = musicIndex;
    loadMusic(musicIndex);
    playMusic();
    playingNow();
}

// play pause btn event
playPauseBtn.addEventListener('click', () => {
    const isMusicPaused = musicPlayer.classList.contains('paused');
    isMusicPaused ? pauseMusic() : playMusic();
    playingNow();
});

// next music btn event
nextBtn.addEventListener('click', () => {
    nextMusic();
});

// prev music btn event
prevBtn.addEventListener('click', () => {
    prevMusic();
});

// vol mute unmute feature
let isMute = false;

const mute = () => {
    isMute = true;
    volMuteBtn.textContent = "volume_off";
    mainAudio.muted = true;
}
const unMute = () => {
    isMute = false;
    volMuteBtn.textContent = "volume_up";
    mainAudio.muted = false;
}

// vol mute unmute btn event
volMuteBtn.addEventListener('click', () => {
    isMute ? unMute() : mute();
});

// update progressbar according to song duration
mainAudio.addEventListener('timeupdate', (e) => {
    // console.log(e);
    const currentTime = e.target.currentTime;
    const duration = e.target.duration;

    let progressWidth = (currentTime / duration) * 100;
    progressBar.style.width = `${progressWidth}%`;

    let musicCurrentTime = musicPlayer.querySelector('.current'),
        musicDuration = musicPlayer.querySelector('.duration');

    mainAudio.addEventListener('loadeddata', () => {
        // update song total duration
        let audioDuration = mainAudio.duration;
        let totalMin = Math.floor(audioDuration / 60);
        let totalSec = Math.floor(audioDuration % 60);
        if (totalMin < 10) {
            totalMin = `0${totalMin}`;
        }
        if (totalSec < 10) {
            totalSec = `0${totalSec}`;
        }
        musicDuration.textContent = `${totalMin}:${totalSec}`;
    });
    // update playing song current time
    let currentMin = Math.floor(currentTime / 60);
    let currentSec = Math.floor(currentTime % 60);
    if (currentMin < 10) {
        currentMin = `0${currentMin}`;
    }
    if (currentSec < 10) {
        currentSec = `0${currentSec}`;
    }
    musicCurrentTime.textContent = `${currentMin}:${currentSec}`;
});

// update song current time according to progress 
progressArea.addEventListener('click', (e) => {
    mainAudio.currentTime = (e.offsetX / progressArea.clientWidth) * mainAudio.duration;
    playMusic();
});

// repeat, shuffle song text according to the icon 
const repeatBtn = musicPlayer.querySelector('#repeat-plist');
repeatBtn.addEventListener('click', () => {
    let getTxt = repeatBtn.textContent;

    switch (getTxt) {
        case "repeat":
            repeatBtn.textContent = "repeat_one";
            repeatBtn.setAttribute('title', 'Song Looped');
            break;

        case "repeat_one":
            repeatBtn.textContent = "shuffle";
            repeatBtn.setAttribute('title', 'Playback Shuffle');
            break;

        case "shuffle":
            repeatBtn.textContent = "repeat";
            repeatBtn.setAttribute('title', 'Playlist Looped');
            break;
    }
});

// repeat shuffle functionality
mainAudio.addEventListener('ended', () => {
    let getTxt = repeatBtn.textContent;

    switch (getTxt) {
        case "repeat":
            nextMusic();
            break;

        case "repeat_one":
            mainAudio.currentTime = 0;
            loadMusic(musicIndex);
            playMusic();
            break;

        case "shuffle":
            let randIndex = Math.floor((Math.random() * songs.length) + 1);
            do {
                randIndex = Math.floor((Math.random() * songs.length) + 1);
            } while (musicIndex == randIndex);
            musicIndex = randIndex;
            loadMusic(musicIndex);
            playMusic();
            playingNow();
            break;
    }
});

// music list set items from song list
const ulTag = document.querySelector('ul');

songs.forEach((elm, index) => {
    let liTag = `<li liIndex="${index + 1}">
                 <div class="row">
                 <span>${elm.name}</span>
                 <p>${elm.artist}</p>
                 </div>
                 <audio class="${elm.src}" src="https://www.mboxdrive.com/${elm.src}.mp3"></audio>
                 <span id="${elm.src}" class="audio-duration">00:00</span>
                 </li>`;
    ulTag.insertAdjacentHTML('beforeend', liTag);

    let liAudioTagDuration = ulTag.querySelector(`#${elm.src}`);
    let liAudioTag = ulTag.querySelector(`.${elm.src}`);

    liAudioTag.addEventListener('loadeddata', () => {
        let audioDuration = liAudioTag.duration;
        let totalMin = Math.floor(audioDuration / 60);
        let totalSec = Math.floor(audioDuration % 60);
        if (totalMin < 10) {
            totalMin = `0${totalMin}`;
        }
        if (totalSec < 10) {
            totalSec = `0${totalSec}`;
        }
        liAudioTagDuration.textContent = `${totalMin}:${totalSec}`;
        liAudioTagDuration.setAttribute('t-duration', `${totalMin}:${totalSec}`);
    });
});

// play particular song on click list item
const allLiTags = ulTag.querySelectorAll('li');

// add class and set duration of playing song
const playingNow = () => {

    allLiTags.forEach((liTag) => {
        let audioDur = liTag.querySelector('.audio-duration');

        if (liTag.classList.contains('playing')) {
            liTag.classList.remove('playing');
            audioDur.textContent = audioDur.getAttribute('t-duration');;
        }

        if (liTag.getAttribute('liIndex') == musicIndex) {
            liTag.classList.add('playing');
            audioDur.textContent = "Playing Now";
        }

        liTag.setAttribute('onclick', "clicked(this)");
    });

}

// play song on click of list item 
const clicked = (el) => {
    let liIndex = el.getAttribute('liIndex');
    musicIndex = liIndex;
    loadMusic(musicIndex);
    playMusic();
    playingNow();
}