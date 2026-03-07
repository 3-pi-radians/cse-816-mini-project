pipeline {
    agent any

    environment {
        PATH = "/opt/homebrew/bin:/usr/local/bin:/usr/bin:/bin:/usr/sbin:/sbin"
    }

    stages {

        stage('Build') {
            steps {
                echo "Building calculator..."
                sh 'make build'
            }
        }

        stage('Test') {
            steps {
                echo "Running tests..."
                sh 'make test'
            }
        }

        stage('Docker Build') {
            steps {
                echo "Building Docker image..."
                sh '/opt/homebrew/bin/docker build -t scientific-calculator .'
            }
        }

        stage('Docker Push') {
            steps {
                echo "Pushing image to Docker Hub..."

                withCredentials([usernamePassword(
                    credentialsId: 'dockerhub-credentials',
                    usernameVariable: 'DOCKER_USER',
                    passwordVariable: 'DOCKER_PASS'
                )]) {

                    sh 'echo $DOCKER_PASS | /opt/homebrew/bin/docker login -u $DOCKER_USER --password-stdin'
                    sh '/opt/homebrew/bin/docker tag scientific-calculator 3piradians/scientific-calculator:latest'
                    sh '/opt/homebrew/bin/docker push 3piradians/scientific-calculator:latest'
                }
            }
        }

        stage('Deploy') {
            steps {
                echo "Deploying container using Ansible..."
                sh 'ansible-playbook -i ansible/hosts ansible/deploy.yml'
            }
}
    }

    post {
        success {
            echo "Pipeline completed successfully"
        }

        failure {
            echo "Pipeline failed"
        }
    }
}