// Store registered users (empty initially)
let registeredUsers = [];
let sampleStudents = [];
let currentCaptcha = 'UiuW';

// Generate random captcha
function generateCaptcha() {
    const chars = 'ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789';
    let captcha = '';
    for (let i = 0; i < 4; i++) {
        captcha += chars.charAt(Math.floor(Math.random() * chars.length));
    }
    return captcha;
}

// Set initial captcha
function generateNewCaptcha() {
    currentCaptcha = generateCaptcha();
    document.getElementById('captchaDisplay').textContent = currentCaptcha;
    document.getElementById('captcha').value = '';
}

// Show specific page and hide others
function showPage(pageId) {
    document.querySelectorAll('.page').forEach(page => {
        page.style.display = 'none';
    });
    document.getElementById(pageId).style.display = 'block';
    
    // Generate new captcha when showing login page
    if (pageId === 'loginPage') {
        generateNewCaptcha();
    }
    
    if (pageId === 'allStudentsPage') {
        loadStudentsData();
    }
}

// Set search type for search page
function setSearchType(type) {
    const searchTitle = document.getElementById('searchTitle');
    const searchHeading = document.getElementById('searchHeading');
    const searchLabel = document.getElementById('searchLabel');
    const searchValue = document.getElementById('searchValue');
    
    if (type === 'name') {
        searchTitle.textContent = 'Search Student by Name';
        searchHeading.textContent = 'Search Student by Name';
        searchLabel.innerHTML = '<i class="fas fa-user icon"></i>Enter Student Name:';
        searchValue.placeholder = 'Enter student name';
    } else {
        searchTitle.textContent = 'Search Student by Roll Number';
        searchHeading.textContent = 'Search Student by Roll Number';
        searchLabel.innerHTML = '<i class="fas fa-id-card icon"></i>Enter Roll Number:';
        searchValue.placeholder = 'Enter roll number';
    }
}

// Load students data into table
function loadStudentsData() {
    const tableBody = document.getElementById('studentsTable');
    tableBody.innerHTML = '';
    
    if (sampleStudents.length === 0) {
        tableBody.innerHTML = `
            <tr>
                <td colspan="5" style="text-align: center; padding: 40px;">
                    <i class="fas fa-exclamation-circle"></i> No student records found
                </td>
            </tr>
        `;
        return;
    }
    
    sampleStudents.forEach(student => {
        const row = document.createElement('tr');
        row.innerHTML = `
            <td>${student.name}</td>
            <td>${student.roll}</td>
            <td>${student.cgpa}</td>
            <td>${student.course}</td>
            <td>${student.stream}</td>
        `;
        tableBody.appendChild(row);
    });
}

// Form handlers
function initializeEventListeners() {
    // Registration form
    document.getElementById('registerForm')?.addEventListener('submit', function(e) {
        e.preventDefault();
        
        const fullName = document.getElementById('fullName').value.trim();
        const username = document.getElementById('regUsername').value.trim();
        const password = document.getElementById('regPassword').value;
        const confirmPassword = document.getElementById('confirmPassword').value;
        
        // Validation
        if (!fullName) {
            alert('Please enter your full name!');
            return;
        }
        
        if (!username) {
            alert('Please enter a username!');
            return;
        }
        
        if (!password) {
            alert('Please enter a password!');
            return;
        }
        
        if (password.length < 6) {
            alert('Password must be at least 6 characters long!');
            return;
        }
        
        if (password !== confirmPassword) {
            alert('Passwords do not match!');
            return;
        }
        
        // Check if username already exists
        const userExists = registeredUsers.find(u => u.username === username);
        if (userExists) {
            alert('Username already exists! Please choose a different username or login.');
            showPage('loginPage');
            document.getElementById('loginUsername').value = username;
            return;
        }
        
        // Save new user
        registeredUsers.push({
            username: username,
            password: password,
            fullname: fullName
        });
        
        // Show success message
        alert(`Registration successful!\n\nUsername: ${username}\nPassword: ${password}\n\nPlease remember your credentials!`);
        
        // Reset form
        document.getElementById('registerForm').reset();
        
        // Show login page with username pre-filled
        showPage('loginPage');
        document.getElementById('loginUsername').value = username;
    });
    
    // Login form
    document.getElementById('loginForm')?.addEventListener('submit', function(e) {
        e.preventDefault();
        
        const username = document.getElementById('loginUsername').value.trim();
        const password = document.getElementById('loginPassword').value;
        const enteredCaptcha = document.getElementById('captcha').value;
        
        // Validation
        if (!username) {
            alert('Please enter your User ID!');
            return;
        }
        
        if (!password) {
            alert('Please enter your password!');
            return;
        }
        
        if (!enteredCaptcha) {
            alert('Please enter the captcha!');
            return;
        }
        
        if (enteredCaptcha !== currentCaptcha) {
            alert('Invalid captcha! Please try again.');
            generateNewCaptcha();
            return;
        }
        
        // Check credentials
        const user = registeredUsers.find(u => u.username === username && u.password === password);
        
        if (user) {
            alert(`Login successful!\nWelcome ${user.fullname}`);
            showPage('dashboardPage');
        } else {
            // Check if username exists but password is wrong
            const userExists = registeredUsers.find(u => u.username === username);
            if (userExists) {
                alert('Incorrect password! Please try again.');
            } else {
                alert('User not found! Please register first.');
                showPage('registerPage');
                document.getElementById('regUsername').value = username;
            }
        }
        
        // Reset password field and generate new captcha
        document.getElementById('loginPassword').value = '';
        generateNewCaptcha();
    });
    
    // Add student form
    document.getElementById('addStudentForm')?.addEventListener('submit', function(e) {
        e.preventDefault();
        
        const name = document.getElementById('studentName').value.trim();
        const roll = document.getElementById('studentRoll').value.trim();
        const cgpa = document.getElementById('studentCGPA').value;
        const course = document.getElementById('studentCourse').value.trim();
        const stream = document.getElementById('studentStream').value;
        
        if (!name || !roll || !cgpa || !course || !stream) {
            alert('Please fill all fields!');
            return;
        }
        
        // Check if roll number already exists
        const rollExists = sampleStudents.find(s => s.roll === roll);
        if (rollExists) {
            alert(`Roll number ${roll} already exists! Please use a different roll number.`);
            return;
        }
        
        // Add to sample data
        sampleStudents.push({
            name: name,
            roll: roll,
            cgpa: parseFloat(cgpa),
            course: course,
            stream: stream
        });
        
        alert(`Student ${name} added successfully!`);
        document.getElementById('addStudentForm').reset();
        showPage('dashboardPage');
    });
    
    // Delete student form
    document.getElementById('deleteStudentForm')?.addEventListener('submit', function(e) {
        e.preventDefault();
        
        const rollToDelete = document.getElementById('deleteRoll').value.trim();
        
        if (!rollToDelete) {
            alert('Please enter a roll number!');
            return;
        }
        
        const index = sampleStudents.findIndex(s => s.roll === rollToDelete);
        
        if (index !== -1) {
            const studentName = sampleStudents[index].name;
            sampleStudents.splice(index, 1);
            alert(`Student ${studentName} (${rollToDelete}) deleted successfully!`);
        } else {
            alert(`Student with Roll Number ${rollToDelete} not found!`);
        }
        
        document.getElementById('deleteStudentForm').reset();
        showPage('dashboardPage');
    });
    
    // Search form
    document.getElementById('searchForm')?.addEventListener('submit', function(e) {
        e.preventDefault();
        
        const searchValue = document.getElementById('searchValue').value.toLowerCase().trim();
        const searchTitle = document.getElementById('searchTitle').textContent;
        const isNameSearch = searchTitle.includes('Name');
        
        if (!searchValue) {
            alert('Please enter a search value!');
            return;
        }
        
        const results = sampleStudents.filter(student => {
            if (isNameSearch) {
                return student.name.toLowerCase().includes(searchValue);
            } else {
                return student.roll.toLowerCase().includes(searchValue);
            }
        });
        
        if (results.length === 0) {
            alert('No students found matching your search!');
            return;
        }
        
        // Create results display
        const resultsBox = document.querySelector('.results-box') || document.createElement('div');
        resultsBox.className = 'results-box';
        resultsBox.innerHTML = `
            <h2 style="color: #2c3e50; margin-bottom: 20px; text-align: center;">Search Results</h2>
            <table class="table">
                <thead>
                    <tr>
                        <th>Name</th>
                        <th>Roll No</th>
                        <th>CGPA</th>
                        <th>Course</th>
                        <th>Stream</th>
                    </tr>
                </thead>
                <tbody>
                    ${results.map(student => `
                        <tr>
                            <td>${student.name}</td>
                            <td>${student.roll}</td>
                            <td>${student.cgpa}</td>
                            <td>${student.course}</td>
                            <td>${student.stream}</td>
                        </tr>
                    `).join('')}
                </tbody>
            </table>
            <div style="text-align: center; margin-top: 30px;">
                <a href="#" class="btn btn-secondary" onclick="showPage('searchPage')">
                    <i class="fas fa-search icon"></i>New Search
                </a>
                <a href="#" class="btn btn-secondary" onclick="showPage('dashboardPage')" style="margin-left: 10px;">
                    <i class="fas fa-arrow-left icon"></i>Back to Dashboard
                </a>
            </div>
        `;
        
        // Replace form with results
        const formBox = document.querySelector('#searchPage .form-box');
        formBox.parentNode.replaceChild(resultsBox, formBox);
    });
}

// Start with registration page
window.onload = function() {
    showPage('registerPage');
    initializeEventListeners();
};