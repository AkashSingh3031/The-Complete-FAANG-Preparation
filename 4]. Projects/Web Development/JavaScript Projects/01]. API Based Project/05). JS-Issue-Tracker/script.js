document.getElementById('issueInputForm').addEventListener('submit', saveIssue);

function fetchIssues () {
    var issues = JSON.parse(localStorage.getItem('issues'));
    var issuesList = document.getElementById('issuesList');
    
    issuesList.innerHTML = '';
    
    for (var i = 0; i < issues.length; i++) {
      var id = issues[i].id;
      var desc = issues[i].description;
      var severity = issues[i].severity;
      var assignedTo = issues[i].assignedTo;
      var status = issues[i].status;
      
      issuesList.innerHTML += '<div class="well">'+
                              '<div class="labid"> <p><span class="label label-info">' + status + '</span></p>'+
                              '<h6>Issue ID: ' + id + '</h6> </div>'+
                              '<h3>' + desc + '</h3>'+
                              '<p><span class="glyphicon glyphicon-time"></span> ' + severity + ' '+
                              '<span class="glyphicon glyphicon-user"></span> ' + assignedTo + '</p>'+
                              '<a href="#" id="closebtn" class="btn btn-warning" onclick="setStatusClosed(\''+id+'\')"><i class="far fa-times-circle"></i> Close</a> '+
                              '<a href="#" id="delbtn" class="btn btn-danger" onclick="deleteIssue(\''+id+'\')"><i class="fas fa-trash"></i> Delete</a>'+
                              '</div>';
    }
}


function saveIssue(e) {
    var issueId = chance.guid();
    var issueDesc = document.getElementById('issueDescInput').value;
    var issueSeverity = document.getElementById('issueSeverityInput').value;
    var issueAssignedTo = document.getElementById('issueAssignedToInput').value;
    var issueStatus = 'Open';
    var issue = {
      id: issueId,
      description: issueDesc,
      severity: issueSeverity,
      assignedTo: issueAssignedTo,
      status: issueStatus
    }
    
    if (localStorage.getItem('issues') === null) {
      var issues = [];
      issues.push(issue);
      localStorage.setItem('issues', JSON.stringify(issues));
    } else {
      var issues = JSON.parse(localStorage.getItem('issues'));
      issues.push(issue);
      localStorage.setItem('issues', JSON.stringify(issues));
    }
    
    document.getElementById('issueInputForm').reset();
    fetchIssues();
    e.preventDefault(); 
}

// close status
function setStatusClosed (id) {
    var issues = JSON.parse(localStorage.getItem('issues'));
    
      for(var i = 0; i < issues.length; i++) {
        if (issues[i].id == id) {
          issues[i].status = "Closed";
        }
      }
    
    localStorage.setItem('issues', JSON.stringify(issues));
    fetchIssues();
}

// delete issue
function deleteIssue (id) {
    var issues = JSON.parse(localStorage.getItem('issues'));
    
    for(var i = 0; i < issues.length; i++) {
      if (issues[i].id == id) {
        issues.splice(i, 1);
      }
    }
    localStorage.setItem('issues', JSON.stringify(issues));
    fetchIssues();
}

//clear all issues
// function clearall () {
//   var issues = JSON.parse(localStorage.getItem('issues'));
//   issues=[];
//   localStorage.setItem('issues', JSON.stringify(issues));
//   fetchIssues();  
// }

// Work in progress 