const addBtn = document.getElementById('addBtn');

const updateNote = () => {
    const textAreaData = document.querySelectorAll('textarea')
    const notes = [];
    textAreaData.forEach((note) => {
        if(note.value != ""){
        return notes.push(note.value);
        }
    });
    localStorage.setItem('notes', JSON.stringify(notes));
}

const addNewNote = (txt = '') => {

    const notesContainer = document.getElementById('notesContainer');
    const note = document.createElement('div');
    const classes = ['note','h-52','p-2','bg-purple-800','rounded','flex','flex-col','shadow-lg','border-b-4','border-yellow-400'];
    note.classList.add(...classes);

    const htmlData = `
        <div class="operation p-0.5 flex justify-end gap-2 mb-0.5">
            <button class="material-icons-round edit bg-green-400 p-1 rounded hover:bg-green-600 hover:text-white transition-colors duration-75">${txt ? "edit_note" : "done" }</button>
            <button class="material-icons-round delete bg-red-600 text-white p-1 rounded hover:bg-red-700 transition-colors duration-75">delete</button>
        </div>

        <div class="noteTxt p-1 overflow-y-auto pb-4 text-white ${txt ? "" : "hidden" }"></div>
        <textarea class="p-1 outline-none border border-yellow-500 rounded resize-none w-full placeholder-gray-500 ${txt ? "hidden" : "" }" rows="6" placeholder="Type your note.."></textarea>`;

    note.insertAdjacentHTML('afterbegin',htmlData);

    const editBtn = note.querySelector('.edit');
    const delBtn = note.querySelector('.delete');
    const noteTxt = note.querySelector('.noteTxt');
    const textArea = note.querySelector('textarea');

    // delete note 
    delBtn.addEventListener('click', () => {
        note.classList.add('animate-ping','opacity-30');
        setTimeout(() => {
            note.remove();
            updateNote();
        }, 200);
    });

    textArea.value = txt;
    noteTxt.innerHTML = txt;

    // edit btn event 
    editBtn.addEventListener('click', () => {
        noteTxt.classList.toggle('hidden');
        textArea.classList.toggle('hidden');
        if(textArea.classList.contains('hidden')) {
            editBtn.textContent = "edit_note";
        } else {
            editBtn.textContent = "done";
        }
        updateNote();
    });

    textArea.addEventListener('change', (event) => {
        const value = event.target.value;
        noteTxt.innerHTML = value;
        if(note.value != ""){
            updateNote();
        }
    });

    notesContainer.appendChild(note);
}

// fetch stored notes from localstorage
const notes = JSON.parse(localStorage.getItem('notes'));
if(notes) {
    notes.forEach((note) => addNewNote(note));
}

// add new note btn event 
addBtn.addEventListener('click', () => addNewNote() );