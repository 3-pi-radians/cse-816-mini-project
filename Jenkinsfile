pipeline {
    agent any

    stages {

    stage('Clone Repository') {
        steps {
            git branch: 'main',
            url: 'https://github.com/3-pi-radians/cse-816-mini-project.git'
        }
    }

        stage('Build') {
            steps {
                sh 'g++ ./src/calculator.cpp -o calculator'
            }
        }

        stage('Test') {
            steps {
                sh './calculator'
            }
        }

        stage('Docker Build') {
            steps {
                sh 'docker build -t calculator-image .'
            }
        }
    }
}