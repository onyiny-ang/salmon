#!/bin/bash

set -o errexit
set -o nounset
set -o pipefail

# Declare an array of TSP data sets
declare -a TSPArray=("berlin52" "dna40" "dna49" "dna67" "dna69" "dna128" "dna174" "dna178")
root_dir="$(cd "$(dirname "$0")/.." ; pwd)"
base_dir="${root_dir}"
temp_dir="${base_dir}/SalmonTSP/temp"
dockerfile_dir="${base_dir}/images/Salmon-TSP/Dockerfile"
cd "$base_dir" || {
  echo "Cannot cd to '$base_dir'. Aborting." >&2
  exit 1

}
cd ${base_dir}

export REGISTRY=quay.io/
export REPO=onyiny_ang

# Set up credentials in travis
echo "Logging into registry ${REGISTRY///}"
docker login -u "${QUAY_USERNAME}" -p "${QUAY_PASSWORD}" quay.io

# Iterate over the TSP data sets
for i in ${TSPArray[@]}; do
    mkdir ${temp_dir}
    cp ${base_dir}/SalmonTSP/${i}/* ${temp_dir}
    cp ${base_dir}/SalmonTSP/base-salmon/* ${temp_dir}
    echo "Building Salmon docker image with tag '${i}'-canary."
    docker build -f ${dockerfile_dir} -t ${REGISTRY}${REPO}/salmon-tsp:${i}-beta .

    echo "Pushing images with tag '${i}'-canary."
    docker push ${REGISTRY}${REPO}/salmon-tsp:${i}-beta

    rm -rf ${temp_dir}
done
