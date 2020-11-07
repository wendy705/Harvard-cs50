document.addEventListener("DOMContentLoaded", function() {

    document.getElementById("add").addEventListener('click', newElement);

    document.getElementById("settings-button").addEventListener('click', openSettings);

    document.getElementById("name-form").addEventListener('submit', function (e) {
       e.preventDefault()
       changeName();
    });

    saveName();

    getGreeting();

    var taskList = localStorage.getItem('taskList');
    if (taskList == undefined || !taskList || taskList.length === 0) {
        taskList = {};
        localStorage.setItem('taskList', JSON.stringify(taskList));
    } else {
        taskList = JSON.parse(taskList);
    }

    Object.keys(taskList).forEach(function (task) {
        appendTask(task, taskList[task]);
    });
});

function appendTask(task, done) {
    var elemList = document.createElement("li");
    elemList.innerHTML = task;
    if (done == true) {
      elemList.className = 'checked';
    }

    elemList.onclick = function (evt) {
        evt.preventDefault();
        evt.stopPropagation();
        this.classList.toggle('checked');

        var currentTaskList = localStorage.getItem('taskList');
        currentTaskList = JSON.parse(currentTaskList);

        currentTaskList[task] = this.classList.contains('checked');
        localStorage.setItem('taskList', JSON.stringify(currentTaskList));
        return false;
    };

    var span = document.createElement("span");
    span.innerHTML = "\u00D7";
    span.className = "myClose";
    span.onclick = function (evt) {
      evt.preventDefault();
      evt.stopPropagation();

      var div = this.parentElement;
      div.style.display = "none";

      var currentTaskList = localStorage.getItem('taskList');
      currentTaskList = JSON.parse(currentTaskList);
      delete currentTaskList[task];
      localStorage.setItem('taskList', JSON.stringify(currentTaskList));
      return false;
    };

    elemList.appendChild(span);
    document.getElementById("myUL").appendChild(elemList);
}


function openSettings() {
    document.getElementById("settings").classList.toggle("settings-open");
}
function saveName(userName) {
    if (userName === undefined) {
        userName = localStorage.getItem('receivedName');
    }
    if (userName.length === 0) {
        userName = "there";
    }
    localStorage.setItem('receivedName', userName);
}

function changeName() {
   userName = document.getElementById("name-input").value;
   saveName(userName);
   getGreeting();
}

function getGreeting() {
    var userName = localStorage.getItem('receivedName');
    document.getElementById("greeting").innerHTML  = `Hello, ${userName}. Enjoy your day!`;
}
// Create a new list item when clicking on the "Add" button
function newElement() {

  var inputValue = document.getElementById("myInput").value;
  if (inputValue === '') {
    alert("You must write something!");
  } else {
    appendTask(inputValue, false);
    document.getElementById("myInput").value = "";

    var currentTaskList = localStorage.getItem('taskList');
    currentTaskList = JSON.parse(currentTaskList);

    currentTaskList[inputValue] = false;
    localStorage.setItem('taskList', JSON.stringify(currentTaskList));
  }
}
