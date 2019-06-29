#!/bin/bash

set -o errexit
set -o nounset
set -o pipefail

# Declare an array of TSP data sets
declare -a TSPArray=("berlin52" "dna40" "dna49" "dna67" "dna69" "dna128"
"dna174" "dna178, dna353, dna443, dna 774")
root_dir="$(cd "$(dirname "$0")/.." ; pwd)"
base_dir="${root_dir}"
temp_dir="${base_dir}/SalmonTSP/temp"
dockerfile_dir="${base_dir}/images/Salmon-TSP/Dockerfile"
cd "$base_dir" || {
  echo "Cannot cd to '$base_dir'. Aborting." >&2
  exit 1

}
cd ${base_dir}

export REGISTRY=quay.io/onyiny_ang/salmon-tsp
export GIT_VERSION=$(git describe --always --dirty)
export GIT_TAG=$(git describe --tags --exact-match 2>/dev/null)

# Set up credentials in travis
echo "Logging into registry ${REGISTRY///}"
docker login -u "${QUAY_USERNAME}" -p "${QUAY_PASSWORD}" quay.io

# Iterate over the TSP data sets
for i in ${TSPArray[@]}; do
    mkdir ${temp_dir}
    cp ${base_dir}/SalmonTSP/${i}/* ${temp_dir}
    cp ${base_dir}/SalmonTSP/base-salmon/* ${temp_dir}
    echo "Building Salmon docker image with tag '${i}'-'${GIT_TAG}'"

    docker build -f ${dockerfile_dir} -t ${REGISTRY} .
    docker tag ${REGISTRY} ${REGISTRY}:${i}-${GIT_VERSION}
    docker push ${REGISTRY}:${i}-${GIT_VERSION}

    echo "Pushing images with 'latest' tag."
    docker tag ${REGISTRY}:${i}-${GIT_VERSION} ${REGISTRY}:${i}-latest
    docker push ${REGISTRY}:${i}-latest


    rm -rf ${temp_dir}
done
