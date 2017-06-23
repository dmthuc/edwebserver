$(function() {

$(document).on('keyup', '#n1, #n2', function() {
  $.ajax({
    url: '/api/v1/sum',
    method: 'POST',
    dataType: 'json',
    data: { n1: $('#n1').val(), n2: $('#n2').val() },
    success: function(json) {
      $('#result').html(json.result);
    }
  });
});

});

$(function() {

$(document).on('keyup', '#n3, #n4', function() {
  $.ajax({
    url: '/api/v1/sum',
    method: 'POST',
    dataType: 'json',
    data: { n1: $('#n3').val(), n2: $('#n4').val() },
    success: function(json) {
      $('#result1').html(json.result);
    }
  });
});

});
function getDate() {
    document.getElementById('date').innerHTML=Date();
    alert("Page is loaded");
}

function hideResult() {
    document.getElementById('result').style.display='none';
}

function showResult() {
    document.getElementById('result').style.display='block';
}
